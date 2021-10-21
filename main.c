#include <stdio.h>
#include <stdlib.h>


typedef struct bloco{
  int id;
  int altura;
  struct bloco* prox;
} bloco;
typedef struct bloco * p_Bloco;

typedef struct Macaco{
  int altura;
  struct bloco* lista_blocos;
} Macaco;
typedef struct Macaco * p_Macaco;

p_Macaco iniciaVetor(int size){
  p_Macaco vector = (p_Macaco) malloc(size * sizeof(Macaco));

  return vector;
}

p_Bloco inicializeVectorBlock(int size){
  p_Bloco vector = (p_Bloco) malloc(size * sizeof(bloco));

  return vector;
}

p_Macaco inicializa_macacos(int nMonkey){
  p_Macaco branch = iniciaVetor(nMonkey);
  for(int i = 0; i < nMonkey; i++){
    branch[i].altura = 0;
    branch[i].lista_blocos = NULL;
  }

  return branch;
}

void bota_no_menor (p_Macaco branch, int nMonkey, int blockId, int blockH){
  p_Bloco auxBlock = inicializeVectorBlock(1);
  auxBlock->altura = blockH;
  auxBlock->id = blockId;
  auxBlock->prox = NULL;
  int menor_indice = 0;
  int menor = branch[0].altura;
  for (int i = 1; i < nMonkey; i++){
    if (branch[i].altura < menor){
      menor = branch[i].altura;
      menor_indice = i;
    }
  }
  branch[menor_indice].altura += blockH;
  auxBlock->prox = branch[menor_indice].lista_blocos;
  branch[menor_indice].lista_blocos = auxBlock;
 }

void imprime_blocos(p_Bloco lista){
  if(lista == NULL) return;
  imprime_blocos(lista->prox);
  printf(" %d %d", lista->id, lista->altura);
}

void imprime_macacos(p_Macaco M, int num_macacos){
  for(int i = 0; i < num_macacos; i++){
    printf("M[%d] altura = %d:", i, M[i].altura);
    imprime_blocos(M[i].lista_blocos);
    printf("\n");
  }
}

void free_list (p_Bloco list){
  if(list == NULL) return;
  free_list(list->prox);
  free(list);
}

void libera_macacos(p_Macaco branch,int nMonkey){
  for(int i = 0; i < nMonkey; i++){
    free_list(branch[i].lista_blocos);
  }
  free(branch);
}


int main(int argc, char * argv[]){
  p_Macaco M;
  int num_macacos;
  int id_bloco;
  int altura_bloco;
  

  scanf("%d", &num_macacos);
  M = inicializa_macacos(num_macacos);
  scanf("%d %d", &id_bloco, &altura_bloco);

  while(id_bloco != -1){
    bota_no_menor(M, num_macacos, id_bloco, altura_bloco);
    scanf("%d %d", &id_bloco, &altura_bloco);
  }

  imprime_macacos(M, num_macacos);
  libera_macacos(M, num_macacos);

  return 0;
}