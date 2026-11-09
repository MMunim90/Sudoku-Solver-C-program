#include<stdio.h>

void print_puzzle(int puzzle[9][9]);
int valid_move(int puzzle[9][9], int row, int column, int val);
int solve_puzzle(int puzzle[9][9], int row, int column);

int main()
{
    printf("\n\tWelcome to SUDOKU Solver !!!\n");

    int puzzle[9][9];

    // input puzzle
    printf("\nInput 9X9 Puzzle (Input 0 onto the empty cell)\n\n");
    for(int row=0; row<9; row++)
    {
        printf("Enter %dth row:- ", row+1);
        for(int column=0; column<9; column++)
        {
            scanf("%d", &puzzle[row][column]);
        }
    }

    printf("\nOriginal Puzzle: \n");
    print_puzzle(puzzle);

    if(solve_puzzle(puzzle, 0, 0))
    {
        printf("\n\nThe puzzle is solved: \n");
        print_puzzle(puzzle);
    }
    else
    {
        printf("\nThis puzzle is not solvable.\n");
    }
    return 0;
}

int solve_puzzle(int puzzle[9][9], int row, int column)
{

    if(column == 9)
    {
        if(row == 8)
        {
            return 1; // puzzle solved
        }
        row++;
        column = 0;
    }

    if(puzzle[row][column] > 0)
    {
        return solve_puzzle(puzzle, row, column+1);
    }


    for(int i=1; i<=9; i++)
    {
        if(valid_move(puzzle, row, column, i))
        {
            puzzle[row][column] = i;
            if(solve_puzzle(puzzle, row, column+1))
            {
                return 1;
            }
            puzzle[row][column] = 0;
        }
    }

    return 0;
}


int valid_move(int puzzle[9][9], int row, int column, int val)
{
    // valid row
    for(int i=0; i<9; i++)
    {
        if(puzzle[row][i] == val)
        {
            return 0;
        }
    }


    // valid column
    for(int i=0; i<9; i++)
    {
        if(puzzle[i][column] == val)
        {
            return 0;
        }
    }


    // valid square
    int r = row - row % 3;
    int c = column - column % 3;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(puzzle[r+i][c+j] == val)
            {
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
