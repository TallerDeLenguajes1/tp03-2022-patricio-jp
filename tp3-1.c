#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int cantNombres = 0;
    char *buffer, **vector/*, *nombre*/;
    buffer = (char *) malloc(100 * sizeof(char));

    printf("Ingrese la cantidad de nombres que desea ingresar: ");
    scanf("%d", &cantNombres);
    fflush(stdin);

    vector = (char **) malloc(cantNombres * sizeof(char *));

    // Bucle para cargar los nombres al vector
    for (int i = 0; i < cantNombres; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        gets(buffer);
        vector[i] = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        // nombre = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        // strcpy(nombre, buffer);
        strcpy(vector[i], buffer);
        // vector[i] = nombre;
    }

    // Bucle para mostrar los datos del vector
    for (int i = 0; i < cantNombres; i++) {
        printf("Nombre %d: %s\n", i + 1, vector[i]);
    }

    // Bucle para liberar la memoria reservada
    for (int i = 0; i < cantNombres; i++) {
        free(vector[i]);
    }

    free(buffer);
    free(vector);
    return 0;
}