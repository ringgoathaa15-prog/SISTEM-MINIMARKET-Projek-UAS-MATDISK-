#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Deklarasi Variabel dan Array
    const int MAX = 50;
    string namaBarang[MAX];
    int hargaBarang[MAX], jumlahBeli[MAX], subTotal[MAX];
    int n, totalBayar = 0;

    cout << "=== SISTEM KASIR MINIMARKET ===\n";
    cout << "Masukkan jumlah jenis item: ";
    cin >> n;

    // 2. Perulangan (For) untuk Input Data
    for (int i = 0; i < n; i++) {
        cout << "\nItem ke-" << i + 1 << endl;
        cout << "Nama Barang  : ";
        cin.ignore(); // Biar input string lancar
        getline(cin, namaBarang[i]);
        cout << "Harga Satuan : ";
        cin >> hargaBarang[i];
        cout << "Jumlah Beli  : ";
        cin >> jumlahBeli[i];

        // Hitung subtotal per item
        subTotal[i] = hargaBarang[i] * jumlahBeli[i];
        totalBayar += subTotal[i];
    }

    // 3. Percabangan (If) untuk Diskon
    int diskon = 0;
    if (totalBayar >= 100000) {
        diskon = totalBayar * 0.1; // Diskon 10% jika belanja >= 100rb
    }

    // 4. Menampilkan Output
    cout << "\n===============================";
    cout << "\n        STRUK BELANJA          ";
    cout << "\n===============================\n";
    for (int i = 0; i < n; i++) {
        cout << namaBarang[i] << " x" << jumlahBeli[i] << " = Rp" << subTotal[i] << endl;
    }
    cout << "-------------------------------";
    cout << "\nTotal Kotor : Rp" << totalBayar;
    cout << "\nDiskon      : Rp" << diskon;
    cout << "\nTotal Bayar : Rp" << totalBayar - diskon;
    cout << "\n===============================\n";

    return 0;
}
