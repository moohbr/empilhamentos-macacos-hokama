Considere o seguinte jogo:
Você tem um conjunto M de macacos empilhadores, identificados de 0 até |M|-1. Você vai recebendo uma sequência de blocos de alturas distintas e precisa dar cada bloco que chega a um dos macacos empilhadores. Quando os blocos acabarem, cada macaco terá empilhado vários blocos, quanto maior a altura da pilha, maior o risco de que eles caiam e tudo se espatife no chão.
Esse jogo tem a seguinte característica:
    ● Você não sabe quantos blocos vão aparecer e nem qual a altura deles.
    ● Quando chegar um “bloco” com número -1 e altura -1 você saberá que os blocos acabaram.
    ● Quando você atribui um bloco a um macaco você não pode tomar de volta.
    ● Existe um algoritmo simples, que costuma dar bons resultados, que é o seguinte:
Você sempre dá o bloco ao macaco com a menor altura no momento (se houver empate, dentre os macacos com menor altura você dá para aquele com menor índice).
Suponha o seguinte exemplo com 3 macacos, inicialmente eles não tem nenhum bloco, portanto suas pilhas são vazias. Chega um bloco com altura 3, como a pilha de todos os macacos têm altura zero, o macaco escolhido será o 0 (zero). Depois chega um bloco com altura 2, como os macacos 1 e 2 tem pilhas com altura zero, o escolhido é o macaco 1. Depois chega o terceiro bloco com altura 4, e agora ele é dado ao macaco 2 pois é o que tem a menor pilha. Agora chega o quarto bloco com altura 3 também, e esse é dado ao macaco 1, pois esse
tem a menor pilha. Chega um quinto bloco, com altura 5 e esse deve ser atribuído ao macaco 1. Por fim chega um bloco com identificação -1 e altura -1 indicando que os blocos acabaram, e o resultado é a altura da maior pilha, neste caso 8.


Para exemplificar considere a seguinte entrada:
3
0 3 1 2 2 4 3 3 4 5 -1 -1
Na saída você deverá imprimir uma identificação de cada macaco, a altura total de sua pilha e a lista com os id e alturas de cada bloco. Na saída abaixo, por exemplo, a linha “M[2] altura = 4: 2 4” demonstra que o macaco 2, tem uma pilha de altura 4, nessa pilha tem bloco com id 2 que tem altura 4. Os blocos de cada pilha devem ser impressos na ordem que foram colocados na pilha.
M[0] altura = 8: 0 3 4 5
M[1] altura = 5: 1 2 3 3
M[2] altura = 4: 2 4