#include <iostream>
using namespace std;
class buku
{
    string judul;

publik
    buku setJudul(string judul)
    {
        this->jduul = judul;
        return *this; // chain function
    }
    string getJudul()
    {
        return this->judul;
    }

} bukunya;

int main()
{
    // bukunya.setJudul("Matematika");
    // cout << bukunya.getJudul();
    cout << bukunya.setJudul("Matematika").getJudul(); // chain function calls
    return 0;
}

// Forward declaration
class Petugas;

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    void tampilkanInfo() {
        cout << "Judul: " << judul 
             << ", Penulis: " << penulis 
             << ", Status: " << (dipinjam ? "Dipinjam" : "Tersedia") 
             << endl;
    }

    // Petugas boleh akses private
    friend class Petugas;
};

class Peminjam {
private:
    string nama;
    int id;

public:
    Peminjam(string n, int i) : nama(n), id(i) {}

    string getNama() { return nama; }
    int getId() { return id; }
};

class Petugas {
private:
    string nama;

public:
    Petugas(string n) : nama(n) {}

    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            cout << "Petugas " << nama << " memproses peminjaman buku oleh " 
                 << p->getNama() << endl;
        } else {
            cout << "Buku sedang dipinjam. Tidak dapat dipinjam lagi.\n";
        }
    }

    