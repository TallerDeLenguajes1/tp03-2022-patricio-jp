#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer, **vector, *nombre;
    buffer = (char *) malloc(100 * sizeof(char));
    vector = (char **) malloc(5 * sizeof(char *));

    // Bucle para cargar los nombres al vector
    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        gets(buffer);
        nombre = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(nombre, buffer);
        vector[i] = nombre;
    }

    // Bucle para mostrar los datos del vector
    for (int i = 0; i < 5; i++) {
        printf("Nombre %d: %s\n", i, vector[i]);
    }

    // Bucle para liberar la memoria reservada
    for (int i = 0; i < 5; i++) {
        free(vector[i]);
    }

    free(buffer);
    free(vector);
    return 0;
}