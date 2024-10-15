#include <iostream>

using namespace std;

const int N = 4;

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

// Función para mostrar los caminos según la matriz A
void mostrarCaminos(int M[N][N], int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "a" << i+1 << "," << j+1 << " = " << A[i][j] << "; ";
            
            if (A[i][j] > 0) {
                cout << "Caminos de " << i+1 << " a " << j+1 << ": ";

                // Aquí puedes agregar condiciones específicas para describir los caminos
                if (i == 0 && j == 0 && A[i][j] == 1) {
                    cout << "I -> K -> I";
                } else if (i == 1 && j == 2 && A[i][j] == 2) {
                    cout << "J -> L -> K y J -> I -> K";
                } else if (i == 3 && j == 1 && A[i][j] == 0) {
                    cout << "No hay caminos intermedios.";
                }
                // Agrega más condiciones si es necesario
                
                cout << endl;
            }
        }
    }
}

int main() {
    // Matriz M de comunicaciones (4x4)
    int M[N][N] = {
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };

    // Matriz A para almacenar el resultado de M * M
    int A[N][N];

    // Multiplicamos M por M y almacenamos el resultado en A
    multiplicarMatrices(M, A);

    // Mostramos la matriz A resultante
    cout << "Matriz A (M^2):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";  // Imprimimos los elementos de la matriz A
        }
        cout << endl;  // Salto de línea para cada fila
    }
    
    // Mostramos los caminos para cada elemento de la matriz A
    cout << endl;
    mostrarCaminos(M, A);

    return 0;
}
