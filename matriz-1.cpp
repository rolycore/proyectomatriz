#include <iostream>
#include <vector>
using namespace std;

const int N = 4;  // Tamaño de la matriz (4x4)

// Función para multiplicar dos matrices de tamaño NxN
void multiplicarMatrices(int M[N][N], int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 0;  // Inicializamos A[i][j] en 0
            for (int k = 0; k < N; k++) {
                A[i][j] += M[i][k] * M[k][j];  // Producto de matrices
            }
        }
    }
}

// Función para mostrar la matriz con etiquetas
void mostrarMatriz(int M[N][N], const char* etiquetas[N]) {
    // Mostrar cabecera con etiquetas
    cout << "  ";
    for (int i = 0; i < N; i++) {
        cout << etiquetas[i] << " ";  // Etiquetas para columnas
    }
    cout << endl;

    // Mostrar las filas con etiquetas y la matriz
    for (int i = 0; i < N; i++) {
        cout << etiquetas[i] << " ";  // Etiqueta de fila
        for (int j = 0; j < N; j++) {
            cout << M[i][j] << " ";  // Valor de la matriz
        }
        cout << endl;
    }
}

// Función para mostrar los caminos de longitud 2 para una posición (i, j)
void mostrarCaminos(int M[N][N], int fila, int columna, const char* etiquetas[N]) {
    cout << "Caminos de " << etiquetas[fila] << " a " << etiquetas[columna] << ":\n";
    for (int k = 0; k < N; k++) {
        if (M[fila][k] == 1 && M[k][columna] == 1) {
            cout << etiquetas[fila] << " -> " << etiquetas[k] << " -> " << etiquetas[columna] << endl;
        }
    }
}

int main() {
    // Definir las etiquetas de los nodos
    const char* etiquetas[N] = {"I", "J", "K", "L"};

    // Matriz M de comunicaciones (4x4)
    int M[N][N] = {
        {0, 0, 1, 0},  // I
        {1, 0, 0, 1},  // J
        {1, 0, 0, 1},  // K
        {1, 1, 1, 0}   // L
    };

    // Matriz A para almacenar el resultado de M * M
    int A[N][N];

    // Multiplicamos M por M y almacenamos el resultado en A
    multiplicarMatrices(M, A);

    // Mostramos la matriz A resultante (M al cuadrado)
    cout << "El resultado de la Matriz M al cuadrado es A (I, J, K, L):" << endl;
    mostrarMatriz(A, etiquetas);
    cout << endl;

    // Pedir al usuario una posición (fila y columna)
    int fila, columna;
    cout << "Introduce la fila (1-" << N << ") y columna (1-" << N << ") para obtener el número de caminos: ";
    cin >> fila >> columna;

    // Ajustar índices para que sean 0-based (de 1-4 a 0-3)
    fila--;
    columna--;

    // Mostrar el valor de A en esa posición
    cout << "El valor en A[" << fila + 1 << "][" << columna + 1 << "] es: " << A[fila][columna] << endl;

    // Mostrar los caminos correspondientes
    if (A[fila][columna] > 0) {
        mostrarCaminos(M, fila, columna, etiquetas);
    } else {
        cout << "No hay caminos de longitud 2 entre esos nodos." << endl;
    }

    return 0;
}
