#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal) {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

    // Pure Virtual Function
    virtual void potongAdmin() = 0;

    void tampilkanInfo() {
        cout << "Nama Nasabah : " << namaNasabah << endl;
        cout << "Saldo        : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 berhasil dipotong." << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 berhasil dipotong." << endl;
        }
    }
};

int main() {

    // Pointer base class
    RekeningBank *rekening1;
    RekeningBank *rekening2;
    RekeningBank *rekening3;

    // Object turunan
    RekeningSyariah syariah("dhika", 5000000);
    RekeningKonvensional konvensional("Haqi", 3000000);
    RekeningPremium premium("Rio", 8000000);

    // Rekening Syariah
    rekening1 = &syariah;
    rekening1->tampilkanInfo();
    rekening1->potongAdmin();
    rekening1->tampilkanInfo();

    cout << "\n========================\n";

    // Rekening Konvensional
    rekening2 = &konvensional;
    rekening2->tampilkanInfo();
    rekening2->potongAdmin();
    rekening2->tampilkanInfo();

    cout << "\n========================\n";

    // Rekening Premium
    rekening3 = &premium;
    rekening3->tampilkanInfo();
    rekening3->potongAdmin();
    rekening3->tampilkanInfo();

    return 0;
}