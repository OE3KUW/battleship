// ***************************************************************
// battle Ship
// ***************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

#define ROWS           10
#define COLS           10

#define LEFT_TOP_X     20
#define LEFT_TOP_Y      2

#define WATER 176
#define WING  177
#define OUT   178
//#define CURSOR 224


void printArray(int **array, int **Carray, int rows, int cols);
void setShips(int **array);

void printArray(int **array, int **Carray, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        {
            textcolor(Carray[i][j]);
            gotoxy(j * 4 + LEFT_TOP_X, i * 2 + LEFT_TOP_Y);
            printf("%c%c%c%c", array[i][j], array[i][j],array[i][j], array[i][j]);
            gotoxy(j * 4 + LEFT_TOP_X, i * 2 + LEFT_TOP_Y + 1);
            printf("%c%c%c%c", array[i][j], array[i][j],array[i][j], array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows = ROWS;
    int cols = COLS;
    int key = 0, lastkey = 0;
    int focusx = 3, focusy = 1;

    initConsole();

    // Speicher für ein 2D-Array allokieren
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }
    // Speicher für ein 2D-Array allokieren
    int **Carray = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        Carray[i] = (int *)malloc(cols * sizeof(int));
    }

    // Das Array mit Werten füllen

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] =   WATER;
            Carray[i][j] =  BLUE;
            if ((i == focusy) && (j == focusx)) Carray[i][j] = MAGENTA;
        }
    }

    setShips(array);
    



    // Übergabe des Arrays an eine Funktion
    printf("Array Inhalt:\n");
    printArray(array, Carray, rows, cols);

    while (key != ESC)
    {

        if (kbhit())
        {
            key = getch();
            if (key != ESC) {
                gotoxy(1, 22);
                printf("key %d lastkey %d", key, lastkey);
                lastkey = key;
            }

        }



    }


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
void setShips(int **array)
{
    int x,y;
    int n = 0;

    while (n < 12)
    {
        x = rand() % (COLS - 2) + 1;
        y = rand() % (ROWS - 2) + 1;

        if ((array[y + 1][x] == WATER) &&
            (array[y - 1][x] == WATER) &&
            (array[y][x + 1] == WATER) &&
            (array[y][x - 1] == WATER) &&
            (array[y][x] == WATER)
                )
        {
            array[y][x] = OUT;
            n++;
        }

    }
}
