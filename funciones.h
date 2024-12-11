struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    int estado;
};
 
int menu();
void registrarLibros(struct Libro libros[20], int* contador);
void mostrarLibros(struct Libro libros[20], int contador);
void buscarLibroId(struct Libro libros[20], int id, int contador);
void buscarLibroTitulo(struct Libro libros[20], char titulo[100], int contador);
void actualizarEstadoLibro(struct Libro libros[20], int id, int contador);
void eliminarLibro(struct Libro libros[20], int id, int* contador);
int verificarIdUnica(struct Libro libros[20], int id);