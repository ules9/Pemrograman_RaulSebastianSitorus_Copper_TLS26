#include <iostream>
using namespace std;


// User-Defined Function untuk mengecek apakah karakter merupakan huruf kapital
bool apakah_kapital(char c) {
    return (c >= 'A' && c <= 'Z');
}

// User-Defined Function untuk merubah teks rahasia
void enkripsi_sandi_alien(const char pesan[]) {
    char pesan_sandi[500];
    int i = 0;
    int prev_val = 0;

    while (pesan[i] != '\0') {
        char c = pesan[i];

        if (apakah_kapital(c)) {
            int orig_val = c - 'A' + 1;
            int new_val = orig_val + prev_val;

            while (new_val > 26) {
                new_val -= 26;
            }

            pesan_sandi[i] = (char)('A' + (new_val - 1));
            prev_val = orig_val;
        } else {
            pesan_sandi[i] = c;
        }
        i++;
    }
    pesan_sandi[i] = '\0';

    cout << "\nHasil Enkripsi Sandi: " << pesan_sandi << "\n";
}

int main() {
    char pesan[500];

    cout << "====================================\n";
    cout << "  PROBLEM 2: ALIEN-IN-THE-MIDDLE    \n";
    cout << "====================================\n";
    cout << "Masukkan pesan asli (Huruf KAPITAL): ";

    // Membaca baris teks input secara manual menggunakan iostream
    cin.getline(pesan, 500);

    enkripsi_sandi_alien(pesan);

    return 0;
}