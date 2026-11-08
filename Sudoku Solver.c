#include<stdio.h>

void print_puzzle(int puzzle[9][9]);

int main()
{

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

    print_puzzle(puzzle);
    return 0;
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
