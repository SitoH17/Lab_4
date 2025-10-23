#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Ver si estan todas las palabras
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <archivo_entrada> <palabra_buscar> <palabra_reemplazo>\n", argv[0]);
        return 1;
    }

    // Intentar abrir el archivo de entrada
    FILE *entrada = fopen(argv[1], "r");
    if (entrada == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    // Crear un archivo 
    FILE *salida = fopen("salida.txt", "w");
    if (salida == NULL) {
        perror("Error al crear el archivo de salida");
        fclose(entrada);
        return 1;
    }

    printf("Archivo de entrada: %s\n", argv[1]);
    printf("Palabra a buscar: %s\n", argv[2]);
    printf("Palabra de reemplazo: %s\n", argv[3]);
    printf("Archivos abiertos correctamente.\n");

    fclose(entrada);
    fclose(salida);

    printf("Archivos cerrados. Fin del programa base.\n");
    return 0;
}
