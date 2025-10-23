#include <stdio.h>
#include <stdlib.h>


// Calcular filas y columnas automáticamente
#define FILAS(x) (sizeof(x) / sizeof((x)[0]))
#define COLUMNAS(x) (sizeof((x)[0]) / sizeof((x)[0][0]))


// Función para imprimir una matriz utilizando punteros
void imprimirMatriz(int *matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", *(matriz + i * columnas + j));
        }
        printf("\n");
    }
    printf("\n");
}
// Uso de BubbleSort

void bubbleSort(int *array, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            int *a = array + j;
            int *b = array + j + 1;
            if (*a > *b) {
                int temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
}


// Función principal
int main() {
    // Matriz 3x3
    int m1[3][3] = {
        {9, 2, 7},
        {5, 1, 3},
        {8, 6, 4}
    };

    int filas1 = FILAS(m1);
    int columnas1 = COLUMNAS(m1);
    int total1 = filas1 * columnas1;

    printf("Matriz 1 original (%dx%d):\n", filas1, columnas1);
    imprimirMatriz((int *)m1, filas1, columnas1);

    bubbleSort((int *)m1, total1);

    printf("Matriz 1 ordenada (%dx%d):\n", filas1, columnas1);
    imprimirMatriz((int *)m1, filas1, columnas1);

    // Matriz 2x4
    int m2[2][4] = {
        {10, 4, 7, 2},
        {8, 1, 9, 3}
    };

    int filas2 = FILAS(m2);
    int columnas2 = COLUMNAS(m2);
    int total2 = filas2 * columnas2;

    printf("Matriz 2 original (%dx%d):\n", filas2, columnas2);
    imprimirMatriz((int *)m2, filas2, columnas2);

    bubbleSort((int *)m2, total2);

    printf("Matriz 2 ordenada (%dx%d):\n", filas2, columnas2);
    imprimirMatriz((int *)m2, filas2, columnas2);

    // Matriz 4x2
    int m3[4][2] = {
        {12, 5},
        {7, 14},
        {1, 9},
        {8, 3}
    };

    int filas3 = FILAS(m3);
    int columnas3 = COLUMNAS(m3);
    int total3 = filas3 * columnas3;

    printf("Matriz 3 original (%dx%d):\n", filas3, columnas3);
    imprimirMatriz((int *)m3, filas3, columnas3);

    bubbleSort((int *)m3, total3);

    printf("Matriz 3 ordenada (%dx%d):\n", filas3, columnas3);
    imprimirMatriz((int *)m3, filas3, columnas3);

    printf("Fin del programa.\n");

    return 0;
}

