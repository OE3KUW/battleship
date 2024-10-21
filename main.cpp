#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

void printArray(int **array, int rows, int cols);
/// Funktion, die das 2D-Array empfängt und es ausgibt

void printArray(int **array, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 3;
    int cols = 4;

    initConsole();



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

    // Speicher freigeben
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
