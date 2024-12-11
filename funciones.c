#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
int menu() {
    int opcion;
    printf("\nMenu:\n");
    printf("1. Registrar libro(s)\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por ID\n");
    printf("4. Buscar libro por Titulo\n");
    printf("5. Actualizar estado de un libro\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
 
int verificarIdUnica(struct Libro libros[20], int id) {
    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            return 0;
        }
    }
    return 1;
}
 
void registrarLibros(struct Libro libros[20], int* contador) {
    int cantidad;
    printf("¿Cuantos libros desea registrar? (Max: %d): ", 20 - *contador);
    scanf("%d", &cantidad);
 
    if (*contador + cantidad > 20) {
        printf("No se pueden registrar mas de 20 libros en total.\n");
        return;
    }
 
    for (int i = 0; i < cantidad; i++) {
        int idValida = 0;
        while (!idValida) {
            printf("\nRegistro del libro %d:\n", *contador + 1);
            printf("Ingrese el ID del libro: ");
            int id;
            scanf("%d", &id);
            if (verificarIdUnica(libros, id)) {
                libros[*contador].id = id;
                idValida = 1;
            } else {
                printf("La ID ingresada ya pertenece a otro libro.\n");
            }
        }
 
        fflush(stdin);
 
        printf("Ingrese el titulo del libro: ");
        fgets(libros[*contador].titulo, 100, stdin);
        int len = strlen(libros[*contador].titulo);
        if (len > 0 && libros[*contador].titulo[len - 1] == '\n') {
            libros[*contador].titulo[len - 1] = '\0';
        }
 
        printf("Ingrese el autor del libro: ");
        fgets(libros[*contador].autor, 50, stdin);
        len = strlen(libros[*contador].autor);
        if (len > 0 && libros[*contador].autor[len - 1] == '\n') {
            libros[*contador].autor[len - 1] = '\0';
        }
 
        printf("Ingrese el anio del libro: ");
        scanf("%d", &libros[*contador].anio);
        libros[*contador].estado = 1; 
 
        printf("Libro registrado correctamente.\n");
        (*contador)++;
    }
}
 
void mostrarLibros(struct Libro libros[20], int contador) {
    if (contador == 0) {
        printf("No hay libros registrados.\n");
        return;
    }
 
    printf("\n%-5s %-30s %-20s %-10s %-15s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    for (int i = 0; i < contador; i++) {
        printf("%-5d %-30s %-20s %-10d %-15s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado == 1 ? "Disponible" : "Prestado");
    }
}
 
void buscarLibroId(struct Libro libros[20], int id, int contador) {
    for (int i = 0; i < contador; i++) {
        if (libros[i].id == id) {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado == 1 ? "Disponible" : "Prestado");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}
 
void buscarLibroTitulo(struct Libro libros[20], char titulo[100], int contador) {
    for (int i = 0; i < contador; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado == 1 ? "Disponible" : "Prestado");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}
 
void actualizarEstadoLibro(struct Libro libros[20], int id, int contador) {
    for (int i = 0; i < contador; i++) {
        if (libros[i].id == id) {
            printf("Estado actual: ");
            if (libros[i].estado == 1) {
                printf("Disponible\n");
            } else {
                printf("Prestado\n");
            }
 
            printf("Ingrese el nuevo estado del libro (1 para Disponible, 2 para Prestado): ");
            int nuevoEstado;
            scanf("%d", &nuevoEstado);
 
            if (nuevoEstado == 1) {
                libros[i].estado = 1;
                printf("Estado actualizado correctamente a: Disponible\n");
            } else if (nuevoEstado == 2) {
                libros[i].estado = 2;
                printf("Estado actualizado correctamente a: Prestado\n");
            } else {
                printf("Estado inválido. No se realizaron cambios.\n");
            }
            return;
        }
    }
    printf("Libro no encontrado.\n");
}
 
void eliminarLibro(struct Libro libros[20], int id, int* contador) {
    for (int i = 0; i < *contador; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *contador - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*contador)--;
            printf("Libro eliminado correctamente.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}