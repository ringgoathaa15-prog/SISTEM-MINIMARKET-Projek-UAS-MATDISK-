#include <iostream>
#include <string>
#include <vector> // Ini kunci biar gak ada batasan barang
#include <iomanip> // Biar output angka lebih rapi

using namespace std;

int main() {
    // Pake vector supaya jumlah barang bebas (tanpa batasan)
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
    cin >> n;

    // Perulangan (Looping) sesuai input user
    for (int i = 0; i < n; i++) {
        cout << "\nData Barang Ke-" << i + 1 << endl;
        cout << "Nama Barang  : ";
        cin.ignore(); // Bersihin buffer biar getline lancar
        getline(cin, inputNama);
        cout << "Harga Satuan : ";
        cin >> inputHarga;
        cout << "Jumlah Beli  : ";
        cin >> inputJumlah;

        // Masukin data ke dalem vector
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
             << subTotal[i] << endl;
    }

    cout << "-----------------------------------------------" << endl;
    cout << "Total Belanja : Rp" << totalKeseluruhan << endl;

    // Percabangan (If) - Logika Diskon
    int diskon = 0;
    if (totalKeseluruhan >= 100000) {
        diskon = totalKeseluruhan * 0.1; // Diskon 10%
        cout << "Diskon (10%)  : Rp" << diskon << endl;
    } else {
        cout << "Diskon        : Rp0 (Belanja min. 100rb buat diskon)" << endl;
    }

    int bayarAkhir = totalKeseluruhan - diskon;
    cout << "TOTAL BAYAR   : Rp" << bayarAkhir << endl;
    cout << "===============================================" << endl;
    cout << "        Terima Kasih Atas Kunjungannya!        " << endl;

    return 0;
}
