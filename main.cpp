#include <iostream>
#include <string>
#include <vector> 
#include <iomanip> 
#include <limits> // Buat ngebersihin buffer sampe tuntas

using namespace std;

int main() {
    vector<string> namaBarang;
    vector<int> hargaBarang;
    vector<int> jumlahBeli;
    vector<int> subTotal;

    string inputNama;
    int inputHarga, inputJumlah, n;
    int totalKeseluruhan = 0;

    cout << "===============================================" << endl;
    cout << "       PROGRAM KASIR MINIMARKET (NIM-4)        " << endl;
    cout << "===============================================" << endl;
    
    cout << "Mau input berapa jenis barang? : ";
    if (!(cin >> n)) return 0; // Proteksi kalo input bukan angka

    // Loop buat tiap barang
    for (int i = 0; i < n; i++) {
        // KUNCINYA DI SINI: Bersihin buffer TOTAL sebelum getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nData Barang Ke-" << i + 1 << endl;
        cout << "Nama Barang  : ";
        getline(cin, inputNama);
        
        cout << "Harga Satuan : ";
        cin >> inputHarga;
        cout << "Jumlah Beli  : ";
        cin >> inputJumlah;

        namaBarang.push_back(inputNama);
        hargaBarang.push_back(inputHarga);
        jumlahBeli.push_back(inputJumlah);
        
        int hitungSub = inputHarga * inputJumlah;
        subTotal.push_back(hitungSub);
        
        totalKeseluruhan += hitungSub;
    }

    // Output Struk Pembayaran
    cout << "\n\n===============================================" << endl;
    cout << "               STRUK PEMBAYARAN                " << endl;
    cout << "===============================================" << endl;
    cout << left << setw(4) << "No" << setw(15) << "Barang" << setw(10) << "Harga" << setw(5) << "Qty" << "Total" << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(4) << i + 1 
             << setw(15) << namaBarang[i] 
             << setw(10) << hargaBarang[i] 
             << setw(5) << jumlahBeli[i] 
             << "Rp" << subTotal[i] << endl;
    }

    cout << "-----------------------------------------------" << endl;
    cout << "Total Belanja : Rp" << totalKeseluruhan << endl;

    int diskon = 0;
    if (totalKeseluruhan >= 100000) {
        diskon = totalKeseluruhan * 0.1; 
        cout << "Diskon (10%)  : Rp" << diskon << endl;
    } else {
        cout << "Diskon        : Rp0 (Belanja min. 100rb buat diskon)" << endl;
    }

    int bayarAkhir = totalKeseluruhan - diskon;
    cout << "TOTAL BAYAR   : Rp" << bayarAkhir << endl;
    cout << "===============================================" << endl;
    cout << "        Terima Kasih Atas Kunjungannya!        " << endl;

    // BIAR JENDELA GAK LANGSUNG TUTUP:
    cout << "\nProgram Selesai. Tekan Enter buat keluar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); 

    return 0;
} 