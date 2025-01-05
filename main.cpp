#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structs for Transaction Processing
struct Produk {
    string kode;
    int jumlah;
    double totalHarga;
};

struct SetoranKasir {
    double setoran = 0;
    double totalPenjualan = 0;
};

// Global Variables
vector<Produk> daftarTransaksi;
SetoranKasir laporan;
const int NUM_PRODUK = 2;
const string produk[NUM_PRODUK] = {"Sosis Ayam", "Sosis Sapi"};
int stok[NUM_PRODUK] = {100, 100};
int masuk[NUM_PRODUK] = {0, 0};
int keluar[NUM_PRODUK] = {0, 0};

// Financial Control Functions
void inputPengeluaran() {
    // Placeholder for input pengeluaran functionality
    cout << "[Financial Control] Input Pengeluaran - Not Implemented\n";
}

// Performance Review Functions
void tambahTransaksi(const string &kode, int jumlah, double hargaSatuan) {
    Produk produk;
    produk.kode = kode;
    produk.jumlah = jumlah;
    produk.totalHarga = jumlah * hargaSatuan;
    daftarTransaksi.push_back(produk);
    laporan.totalPenjualan += produk.totalHarga;
}

void laporanPerforma() {
    cout << "\n=== Laporan Performa ===\n";
    double labaKotor = laporan.totalPenjualan - 70000; // Example HPP
    double labaBersih = labaKotor - 50000;             // Example Biaya Operasional

    cout << "Total Penjualan: Rp " << laporan.totalPenjualan << endl;
    cout << "Laba Kotor: Rp " << labaKotor << endl;
    cout << "Laba Bersih: Rp " << labaBersih << endl;
}

// Inventory Management Functions
void inputStok() {
    int pilihanProduk, jumlah, tipeTransaksi;
    cout << "\nPilih Produk:\n";
    for (int i = 0; i < NUM_PRODUK; i++) {
        cout << i + 1 << ". " << produk[i] << " (Stok: " << stok[i] << ")\n";
    }
    cin >> pilihanProduk;
    cout << "1. Tambah Stok\n2. Kurangi Stok\nPilihan: ";
    cin >> tipeTransaksi;
    cout << "Masukkan jumlah: ";
    cin >> jumlah;

    if (tipeTransaksi == 1) {
        stok[pilihanProduk - 1] += jumlah;
        masuk[pilihanProduk - 1] += jumlah;
    } else {
        if (stok[pilihanProduk - 1] >= jumlah) {
            stok[pilihanProduk - 1] -= jumlah;
            keluar[pilihanProduk - 1] += jumlah;
        } else {
            cout << "Stok tidak mencukupi.\n";
        }
    }
}

void tampilkanStok() {
    cout << "\nSisa Stok:\n";
    for (int i = 0; i < NUM_PRODUK; i++) {
        cout << produk[i] << ": " << stok[i] << endl;
    }
}

// Transaction Processing Functions
void inputPenjualan() {
    Produk produk;
    double hargaSatuan;
    cout << "\nMasukkan kode produk: ";
    cin >> produk.kode;
    cout << "Masukkan harga satuan produk: ";
    cin >> hargaSatuan;
    cout << "Masukkan jumlah produk: ";
    cin >> produk.jumlah;

    produk.totalHarga = hargaSatuan * produk.jumlah;
    daftarTransaksi.push_back(produk);
    laporan.totalPenjualan += produk.totalHarga;

    cout << "Transaksi berhasil dicatat!\n";
}

void cetakNota() {
    double totalSemua = 0.0;
    cout << "\nNota Penjualan:\n";
    for (const auto &produk : daftarTransaksi) {
        cout << "Kode: " << produk.kode << ", Jumlah: " << produk.jumlah << ", Total: Rp " << fixed << setprecision(2) << produk.totalHarga << endl;
        totalSemua += produk.totalHarga;
    }
    cout << "Total Semua Transaksi: Rp " << totalSemua << endl;
}

// Unified Menu
void tampilkanMenuUtama() {
    cout << "\n===== Sistem Manajemen Bisnis =====\n";
    cout << "1. Financial Control\n";
    cout << "2. Performance Review\n";
    cout << "3. Inventory Management\n";
    cout << "4. Transaction Processing\n";
    cout << "0. Keluar\n";
    cout << "Pilihan Anda: ";
}

int main() {
    int pilihan;

    do {
        tampilkanMenuUtama();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputPengeluaran();
                break;
            case 2:
                laporanPerforma();
                break;
            case 3:
                tampilkanStok();
                inputStok();
                break;
            case 4:
                inputPenjualan();
                cetakNota();
                break;
            case 0:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 0);

    return 0;
}
