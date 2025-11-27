#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

double A[10][11];

// fungsi untuk menghasilkan angka random 0–10
double acak() {
    return rand() % 11;
}

// fungsi menampilkan matriks
void tampilkan() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 11; j++) {
            cout << setw(8) << fixed << setprecision(2) << A[i][j];
            if (j == 9) cout << " |";
        }
        cout << endl;
    }
    cout << endl;
}

// metode eliminasi gauss (tanpa jordan)
void eliminasiGauss() {
    int n = 10;
    for (int i = 0; i < n - 1; i++) {
        // pivot jika elemen diagonal 0
        if (A[i][i] == 0) {
            for (int k = i + 1; k < n; k++) {
                if (A[k][i] != 0) {
                    for (int j = 0; j <= n; j++) {
                        swap(A[i][j], A[k][j]);
                    }
                    break;
                }
            }
        }

        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= n; j++) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }
}

// substitusi balik
void substitusiBalik() {
    int n = 10;
    double x[10];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = A[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    cout << "Hasil penyelesaian (metode eliminasi Gauss):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << endl;
    }
}

int main() {
    srand(time(0));

    double b[10] = {1, -1, 1, -1, 1, -1, 1, -1, 1, -9};

    // inisialisasi matriks A (10x10) dan vektor b
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 11; j++) {
            if (i == 0 && j == 0) {
                A[i][j] = 0; // a(0,0) = 0
            } else if (j == 10) {
                A[i][j] = b[i]; // kolom terakhir = vektor b
            } else {
                A[i][j] = acak(); // nilai acak 0–10
            }
        }
    }

    cout << "Matriks Augmented Awal:" << endl;
    tampilkan();

    eliminasiGauss();

    cout << "Setelah Eliminasi Gauss:" << endl;
    tampilkan();

    substitusiBalik();

    return 0;
}
