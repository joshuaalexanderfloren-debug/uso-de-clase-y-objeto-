#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Definición de la clase Libro
class Libro {
private:
    // Atributos privados (Encapsulación)
    string titulo;
    string autor;
    int anioPublicacion;
    string edicion;
    int cantidadPaginas;

public:
    // Constructor por defecto
    Libro() : titulo(""), autor(""), anioPublicacion(0), edicion(""), cantidadPaginas(0) {}

    // Método para ingresar los datos del libro desde el teclado
    void pedirDatos(int numeroLibro) {
        cout << "\n----------------------------------------" << endl;
        cout << "   Ingrese datos del Libro #" << numeroLibro << endl;
        cout << "----------------------------------------" << endl;
        
        cout << "Título: ";
        getline(cin >> ws, titulo);
        
        cout << "Autor: ";
        getline(cin, autor);
        
        cout << "Año de publicación: ";
        while (!(cin >> anioPublicacion)) {
            cout << "Por favor, ingrese un número válido para el año: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Edición (ej. 1ra, 2da): ";
        getline(cin >> ws, edicion);

        cout << "Cantidad de páginas: ";
        while (!(cin >> cantidadPaginas)) {
            cout << "Por favor, ingrese un número válido de páginas: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Método público para mostrar la información del libro
    void mostrarInformacion() const {
        cout << "----------------------------------------" << endl;
        cout << "Título: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Año de publicación: " << anioPublicacion << endl;
        cout << "Edición: " << edicion << endl;
        cout << "Cantidad de páginas: " << cantidadPaginas << endl;
    }
};

int main() {
    const int TOTAL_LIBROS = 5;
    vector<Libro> biblioteca(TOTAL_LIBROS);

    cout << "========================================" << endl;
    cout << "  SISTEMA DE REGISTRO DE LIBROS (POO)   " << endl;
    cout << "========================================" << endl;

    // Estructura de control (bucle) para pedir 5 libros
    for (int i = 0; i < TOTAL_LIBROS; i++) {
        biblioteca[i].pedirDatos(i + 1);
    }

    // Mostrar los libros ingresados
    cout << "\n========================================" << endl;
    cout << "    MOSTRANDO INFORMACIÓN DE LIBROS     " << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < TOTAL_LIBROS; i++) {
        cout << "\nLibro #" << (i + 1) << ":" << endl;
        biblioteca[i].mostrarInformacion();
    }

    return 0;
}
