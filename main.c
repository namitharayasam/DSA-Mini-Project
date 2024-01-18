#include "SudokuSolver.h"

// function to print the sudoku puzzle
void printSudoku(int puzzle[N][N])
{
    for (int row = 0; row < N; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            printf("+-----|-------|------+\n");
        }
        for (int col = 0; col < N; col++)
        {
            if (col % 3 == 0 && col != 0)
            {
                printf("| ");
            }
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() 
{
    int puzzle[N][N];

    // taking user input for the sudoku puzzle
    printf("Enter the sudoku puzzle (enter 0 for empty cells):\n");
    for (int i = 0; i < N; i++) 
    {
        printf("Enter numbers for row %d (separated by space): ", i + 1);
        int numCount = 0;  //counter for the number of inputs in the row
        for (int j = 0; j < N; j++) 
        {
            while (1) 
            {
                char* num;
                if (scanf(" %s", &num) == 1) 
                {
                    int x = num - '0';
                    if (x >= 0 && x <= 9) 
                    {
                        puzzle[i][j] = x;
                        numCount++;
                        break;
                    } 
                    else 
                    {
                        printf("Please enter a number between 0 and 9.\n");
                        continue;
                    }
                } 
                else 
                {
                    printf("Invalid input. Please enter 9 numbers separated by space.\n");
                }
            }
        }

        //check if the user entered less than 9 numbers in the row
        if (numCount < N) 
        {
            printf("Invalid input. Please enter exactly 9 numbers.\n");
            i--;  //prompt the user to re-enter the current row
        }
    }

    if (solveSudoku(puzzle)) 
    {
        printf("\nThe Solved Sudoku:\n");
        printSudoku(puzzle);
    } 
    else 
    {
        printf("\nNo solution exists.\n");
        printf("\nKindly check for any errors in the puzzle while entering and try again.\n");
        printf("\n");
    }

    return 0;
}