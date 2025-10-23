
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Quita los signos para comparar las palabras
void limpiarParaComparar(const char *origen, char *destino) {
    int j = 0;
    for (int i = 0; origen[i] != '\0'; i++) {
        if (isalnum((unsigned char)origen[i])) {
            destino[j++] = origen[i];
        }
    }
    destino[j] = '\0';
}

// Función principal
int main(int argc, char *argv[]) {

    // Ver si estan todas las palabras
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <archivo_entrada> <palabra_buscar> <palabra_reemplazo>\n", argv[0]);
        return 1;
    }

    // Abrir el archivo
    FILE *entrada = fopen(argv[1], "r");
    if (entrada == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    FILE *salida = fopen("salida.txt", "w");
    if (salida == NULL) {
        perror("Error al crear el archivo de salida");
        fclose(entrada);
        return 1;
    }

    const char *buscar = argv[2];
    const char *reemplazo = argv[3];
    char palabra[256];
    char palabraComparada[256];

    // Leer cada carácter

    int c;
    while ((c = fgetc(entrada)) != EOF) {

        // Si el carácter no es espacio, empezamos a leer una palabra
        if (!isspace(c)) {
            ungetc(c, entrada); // devolvemos el carácter leído
            if (fscanf(entrada, "%255s", palabra) == 1) {

                limpiarParaComparar(palabra, palabraComparada);

                if (strcasecmp(palabraComparada, buscar) == 0) {
                    int inicio = 0;
                    int fin = strlen(palabra) - 1;

                    if (ispunct((unsigned char)palabra[fin])) {
                        fprintf(salida, "%s%c", reemplazo, palabra[fin]);
                    } else if (ispunct((unsigned char)palabra[inicio])) {
                        fprintf(salida, "%c%s", palabra[inicio], reemplazo);
                    } else {
                        fprintf(salida, "%s", reemplazo);
                    }
                } else {
                    // Si no coincide, escribir palabra original
                    fprintf(salida, "%s", palabra);
                }
            }
        } else {
            fputc(c, salida);
        }
    }

    // Cierre de archivos
    fclose(entrada);
    fclose(salida);

    printf("Reemplazo completado con éxito.\n");
    printf("Archivo modificado guardado como 'salida.txt'\n");
    return 0;
}
