// header file

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// defining the sudoku size
#define N 9

bool isAllowed(int puzzle[N][N], int row, int col, int num);
bool solveSudoku(int puzzle[N][N]);
void printSudoku(int puzzle[N][N]);