# monkey-stacking-hokama

Consider the following game: 
You have a set M of stacker monkeys, labeled 0 through |M|-1. 
You will receive a sequence of blocks of different heights and you need to give each block that arrives to one of the stacker monkeys. When the blocks run out, each monkey will have piled up several blocks, the higher the height of the pile, the greater the risk that they will fall and everything will crash to the ground. This game has the following feature:

- ● You don't know how many blocks will appear or how tall they are. ● When a “block” with number -1 and height -1 arrives, you will know that the blocks have run out. ● When you assign a block to a monkey you cannot take it back. 

- ● There is a simple algorithm, which usually gives good results, which is the following: You always give the block to the monkey with the lowest height at the moment (if there is a tie, among the monkeys with the smallest height you give to the one with the smallest index). Assume the following example with 3 monkeys, initially they don't have any blocks, so their piles are empty. A block with height 3 arrives, as the pile of all monkeys has zero height, the monkey chosen will be 0 (zero). Then a block with height 2 arrives, as monkeys 1 and 2 have piles of zero height, the chosen one is monkey 1. Then the third block with height 4 arrives, and now it is given to monkey 2 because it is the one with the smallest pile. Now comes the fourth block with height 3 as well, and this is given to monkey 1 because it has the smallest pile. A fifth block arrives, with height 5 and this must be assigned to monkey 1. Finally, a block with identification -1 and height -1 arrives, indicating that the blocks are finished, and the result is the height of the largest pile, in this case 8.

As an example, consider the following input: 3 0 3 1 2 2 4 3 3 4 5 -1 -1 
In the output you must print an identification of each monkey, the total height of its stack and the list with the id and heights of each block. In the output below, for example, the line “M[2] height = 4: 2 4” demonstrates that monkey 2, has a stack of height 4, in this stack there is a block with id 2 that has height 4. The blocks of each stack must be printed in the order they were placed on the stack.
M[0] height = 8: 0 3 4 5
M[1] height = 5: 1 2 3 3 
M[2] height = 4: 2 4
