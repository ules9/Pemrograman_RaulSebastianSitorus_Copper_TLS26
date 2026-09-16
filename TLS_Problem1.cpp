#include <iostream>
using namespace std;

// Fungsi untuk mengeksekusi eliminasi astronot
void jalankan_eliminasi(int N, int K) {
    // Menggunakan array dengan batas maksimum 
    int astronot[1000];
    bool dieliminasi[1000];

    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
        dieliminasi[i] = false;
    }

    int pos = 0;
    int tereliminasi_count = 0;
    int astronot_terakhir = -1;

    cout << "\n=== URUTAN ELIMINASI ASTRONOT ===\n";

    while (tereliminasi_count < N) {
        int hitung = 0;

        while (hitung < K) {
            if (!dieliminasi[pos]) {
                hitung++;
                if (hitung == K) {
                    break;
                }
            }
            pos = (pos + 1) % N;
        }

        dieliminasi[pos] = true;
        tereliminasi_count++;
        int no_astronot = astronot[pos];
        astronot_terakhir = no_astronot;

        cout << "Eliminasi ke-" << tereliminasi_count << 
                ": Astronot Nomor " << no_astronot << "\n";
          

        // Aturan nilai K
        if (no_astronot % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        if (K < 2) {
            K = 2;
        }

        // Cari posisi awal berikutnya yang belum tereliminasi
        if (tereliminasi_count < N) {
            while (dieliminasi[pos]) {
                pos = (pos + 1) % N;
            }
        }
    }

    cout << "\n-----------------------------------\n";
    cout << "Astronot terakhir yang bertahan: " << astronot_terakhir << "\n";
    cout << "-----------------------------------\n";
}

int main() {
    int N, K;

    cout << "====================================\n";
    cout << "   PROBLEM 1: THE LAST ASTRONAUT    \n";
    cout << "====================================\n";
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai eliminasi awal (K): ";
    cin >> K;

    if (N <= 0 || K < 2) {
        cout << "Input tidak valid! N harus > 0 dan K minimal 2.\n";
        return 1;
    }

    jalankan_eliminasi(N, K);

    return 0;
}