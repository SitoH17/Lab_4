#include <stdio.h>
#include <stdlib.h>
int main() {
    // Prueba con matriz 3x3
    int m1[3][3] = {
        {9, 2, 7},
        {5, 1, 3},
        {8, 6, 4}
    };
    int filas1 = 3, columnas1 = 3;
    int total1 = filas1 * columnas1;

    printf("Matriz original 3x3:\n");
    imprimirMatriz((int *)m1, filas1, columnas1);

    bubbleSort((int *)m1, total1);

    printf("Matriz ordenada 3x3:\n");
    imprimirMatriz((int *)m1, filas1, columnas1);

    // Prueba con matriz 2x4
    int m2[2][4] = {
        {10, 4, 7, 2},
        {8, 1, 9, 3}
    };
    int filas2 = 2, columnas2 = 4;
    int total2 = filas2 * columnas2;

    printf("Matriz original 2x4:\n");
    imprimirMatriz((int *)m2, filas2, columnas2);

    bubbleSort((int *)m2, total2);

    printf("Matriz ordenada 2x4:\n");
    imprimirMatriz((int *)m2, filas2, columnas2);

    // Prueba con matriz 4x2
    int m3[4][2] = {
        {12, 5},
        {7, 14},
        {1, 9},
        {8, 3}
    };
    int filas3 = 4, columnas3 = 2;
    int total3 = filas3 * columnas3;

    printf("Matriz original 4x2:\n");
    imprimirMatriz((int *)m3, filas3, columnas3);

    bubbleSort((int *)m3, total3);

    printf("Matriz ordenada 4x2:\n");
    imprimirMatriz((int *)m3, filas3, columnas3);

    return 0;
}
