#include<stdio.h>

void print_puzzle(int puzzle[9][9]);
int valid_move(int puzzle[9][9], int row, int column, int val);

int main()
{
    printf("\n\tWelcome to SUDOKU Solver !!!\n");
    printf("\nOriginal Puzzle: ");

    int puzzle[9][9] =
    {
        {3,0,0,0,2,0,0,7,0},
        {9,0,0,5,0,0,0,1,4},
        {0,1,6,3,7,0,0,0,8},
        {2,0,0,8,0,0,0,0,1},
        {5,0,0,0,4,1,8,0,0},
        {0,8,9,0,0,0,0,5,0},
        {0,0,5,0,1,0,2,8,0},
        {0,4,0,0,0,6,0,9,3},
        {7,3,1,0,8,2,0,0,0}
    };



//    int puzzle[9][9];
//
////     input puzzle
//    for(int row=0; row<9; row++){
//        for(int column=0; column<9; column++){
//            scanf("%d", &puzzle[row][column]);
//        }
//        printf("\n");
//    }

    print_puzzle(puzzle);
//    printf("%d", valid_move(puzzle, 0, 1, 3));
//    printf("%d", valid_move(puzzle, 0, 1, 5));
    return 0;
}


int valid_move(int puzzle[9][9], int row, int column, int val){
    // valid row
    for(int i=0; i<9; i++){
        if(puzzle[row][i] == val){
            return 0;
        }
    }


    // valid column
    for(int i=0; i<9; i++){
        if(puzzle[i][column] == val){
            return 0;
        }
    }


    // valid square
     int r = row - row % 3;
     int c = column - column % 3;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(puzzle[r+i][c+j] == val){
                return 0;
            }
        }
    }

    return 1;

}

void print_puzzle(int puzzle[9][9])
{
    printf("\n+-----------------------+");

    for(int row=0; row<9; row++)
    {
        if(row % 3 == 0 && row != 0)
        {
            printf("\n|-------+-------+-------|");
        }
        printf("\n");
        for(int column=0; column<9; column++)
        {
            if(column % 3 == 0)
            {
                printf("| ");
            }
            if(puzzle[row][column] != 0)
            {
                printf("%d ", puzzle[row][column]);

            }
            else
            {
                printf("  ");
            }
        }
        printf("|");
    }

    printf("\n+-----------------------+\n");

}
