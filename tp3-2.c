#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

// typedef struct Producto Producto;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
} Cliente;

// typedef struct Cliente Cliente;

float costoTotal(Producto producto);

int main() {
    srand(time(NULL));
    int cantClientes = 0;
    char *buffer;
    buffer = (char *) malloc(100 * sizeof(char));

    printf("==============================\n");
    printf("====== Modulo preventas ======\n");
    printf("==============================\n");
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    fflush(stdin);

    Cliente *clientes;
    clientes = (Cliente *) malloc(cantClientes * sizeof(Cliente));
    
    printf("\nA continuacion debera cargar la informacion de el/los cliente/s\n");
    for (int i = 0; i < cantClientes; i++) {
        printf("Ingrese el nombre del cliente %d: ", i + 1);
        gets(buffer);
        clientes[i].NombreCliente = (char *) malloc((strlen(buffer) + 1) * sizeof(char)); // Reservar espacio en memoria para el nombre del cliente
        strcpy(clientes[i].NombreCliente, buffer); // Copiar nombre del cliente ingresado

        clientes[i].ClienteID = i + 1; // Asignar ID al cliente (correlativo)
        
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1; // Asignar numero aleatorio de cantidad de productos

        clientes[i].Productos = (Producto *) malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto)); // Asignar memoria para la cantidad de productos generada

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            // Asignar productos aleatoriamente, salvo el ID el cual es correlativo
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            // strcpy(clientes[i].Productos[j].TipoProducto, TiposProductos[rand() % 5]);
        }
    }

    printf("\n======= Resultados ========");
    for (int i = 0; i < cantClientes; i++) {
        float totalCliente = 0;
        printf("\n---- Cliente %d ----\n", i + 1);
        printf("ID: %d\n", clientes[i].ClienteID);
        printf("Nombre: %s\n", clientes[i].NombreCliente);
        printf("Cantidad de productos pedidos: %d\n", clientes[i].CantidadProductosAPedir);
        printf("--- Productos ---\n");
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            printf("ID producto: %d\n", clientes[i].Productos[j].ProductoID);
            printf("Tipo producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Precio unitario: $%.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("Costo total del producto: $%.2f\n\n", costoTotal(clientes[i].Productos[j]));
            totalCliente += costoTotal(clientes[i].Productos[j]);
        }
        printf("\nTotal a pagar por el cliente: $%.2f\n\n", totalCliente);
    }

    free(buffer);
    for (int i = 0; i < cantClientes; i++) {
        /*for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            free(&(clientes[i].Productos[j]));
        }*/
        free(clientes[i].Productos);
        // free(&(clientes[i]));
    }
    free(clientes);
    return 0;
}

float costoTotal(Producto producto) {
    return producto.PrecioUnitario * producto.Cantidad;
}
