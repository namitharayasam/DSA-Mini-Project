// Implementation File:

#include "SudokuSolver.h"
#include <stdio.h>

// function to check if a number can be placed in a given cell
bool isAllowed(int puzzle[N][N], int row, int col, int num)
{
    // check if the number exists in the current row or column
    for (int i = 0; i < N; i++)
    {
        if (puzzle[row][i] == num || puzzle[i][col] == num)
        {
            return false;
        }
    }

    // check if the number exists in the current 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzle[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// function to solve the sudoku puzzle using backtracking
bool solveSudoku(int puzzle[N][N])
{
    int row, col;

    // find an empty cell
    bool empty_cell = false;
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (puzzle[row][col] == 0)
            {
                empty_cell = true;
                break;
            }
        }
        if (empty_cell)
        {
            break;
        }
    }

    // when there are no empty cells, the puzzle is solved
    if (!empty_cell)
    {
        return true;
    }

    // try to place a number in the empty cell
    for (int num = 1; num <= N; num++)
    {
        if (isAllowed(puzzle, row, col, num))
        {
            puzzle[row][col] = num;

            // recursively solve for the rest of the puzzle
            if (solveSudoku(puzzle))
            {
                return true;
            }

            // if placing the number doesn't lead to a solution, backtrack
            puzzle[row][col] = 0;
        }
    }

    // if no number can be placed, return false
    return false;
}