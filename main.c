// ***************************************************************
// battle Ship
// ***************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

#define ROWS           10
#define COLS           10

#define LEFT_TOP_X     10
#define LEFT_TOP_Y      2

/// WHAT4: Show Array
/// IN: Address of 2-dim array, rows, cols
/// PRE: Memory must be allocated
void printArray(int **array, int rows, int cols);

void printArray(int **array, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        {
            gotoxy(j * 3 + LEFT_TOP_X
                   , i + LEFT_TOP_Y);
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows = ROWS;
    int cols = COLS;

    initConsole();
    printf("start");
    getch();

    // Speicher für ein 2D-Array allokieren
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    // Das Array mit Werten füllen
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = value++;
        }
    }

    // Übergabe des Arrays an eine Funktion
    printf("Array Inhalt:\n");
    printArray(array, rows, cols);

    getch();
    // Speicher freigeben
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
    clrscr();
    closeConsole();
    return 0;
}
