#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) 

{
    struct Libro libros[20] = {0};
    int opcion;
    int contador = 0;
 
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                registrarLibros(libros, &contador);
                break;
            case 2:
                mostrarLibros(libros, contador);
                break;
            case 3:
                printf("Ingrese el ID del libro a buscar: ");
                int id;
                scanf("%d", &id);
                buscarLibroId(libros, id, contador);
                break;
            case 4:
                printf("Ingrese el titulo del libro a buscar: ");
                char titulo[100];
                getchar();
                fgets(titulo, 100, stdin);
                int len = strlen(titulo);
                if (len > 0 && titulo[len - 1] == '\n') {
                    titulo[len - 1] = '\0';
                }
                buscarLibroTitulo(libros, titulo, contador);
                break;
            case 5:
                printf("Ingrese el ID del libro para actualizar su estado: ");
                scanf("%d", &id);
                actualizarEstadoLibro(libros, id, contador);
                break;
            case 6:
                printf("Ingrese el ID del libro a eliminar: ");
                scanf("%d", &id);
                eliminarLibro(libros, id, &contador);
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 7);
 
    return 0;
}