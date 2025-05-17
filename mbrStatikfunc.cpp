#include <iostream>
#include <string>
using namespace std;

class mahasiswa{
private:
    static int nim;
public:
    int id;
    string nama;

    void setID();
    void printAll();

    static void setNim(int pNim){nim=pNim; /*Definisi Function*/}
    static int getNim(){return nim; /*Definisi Function*/}

    mahasiswa(string pnama):nama(pnama){setID();}
};

int mahasiswa::nim=0;

void mahasiswa::setID(){
    ID = ++nim;
}

void mahasiswa::printAll(){
    cout<<"ID = "<<id<endl;
    cout<<"Nama = "<<nama<endl;
    cout<<endl;
}

int main(){
    mahasiswa mhs1("Sri Dadi");
    mahasiswa mhs 2("Budi Jatmiko");
    mahasiswa::setNim(9); //mengakses nim melalui static member function "setNim"
    mahasiswa mhs3("Andi Janu");
    mahasiswa mhs4("Joko Wahono");

    mhs1.printAll();
    mhs2.printAll();
    mhs3.printAll();
    mhs4.printAll();

    cout<<"akses dari luar object = "<<mahasiswa::getNim()<<endl; //mengakses nim melalui static member function "getNim"

    return 0;
}

// Forward declaration
class Admin;

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

    friend void lihatStatusBuku(const Buku& b, const Admin& a);
    friend class Petugas;
};

class Peminjam {
private:
    string nama;
    int id;
    int totalPinjaman;

public:
    Peminjam(string n, int i) : nama(n), id(i), totalPinjaman(0) {}

    void tampilkanInfo() {
        cout << "Nama: " << nama 
             << ", ID: " << id 
             << ", Total Pinjaman: " << totalPinjaman 
             << endl;
    }

    string getNama() { return nama; }

    friend void lihatStatistikPeminjam(const Peminjam& p, const Admin& a);
    friend class Petugas;
};

class Petugas {
private:
    string nama;
    int idPetugas;
    string levelAkses;

public:
    Petugas(string n, int id, string level) 
        : nama(n), idPetugas(id), levelAkses(level) {}

    void tampilkanInfo() {
        cout << "Nama Petugas: " << nama 
             << ", ID: " << idPetugas 
             << ", Level Akses: " << levelAkses 
             << endl;
    }

    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->totalPinjaman++;
            cout << "Peminjaman berhasil oleh " << p->getNama() << endl;
        } else {
            cout << "Buku sedang dipinjam.\n";
        }
    }

    void prosesKembali(Buku* b, Peminjam* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            if (p->totalPinjaman > 0) p->totalPinjaman--;
            cout << "Pengembalian berhasil oleh " << p->getNama() << endl;
        } else {
            cout << "Buku belum dipinjam.\n";
        }
    }
};

class Admin {
private:
    string nama;

public:
    Admin(string n) : nama(n) {}

    void tampilkanInfo() {
        cout << "Admin: " << nama << endl;
    }

    // Admin hanya bisa memanggil fungsi friend ini (akses terbatas)
    void lihatDataStatistik(const Peminjam& p, const Buku& b) {
        lihatStatistikPeminjam(p, *this);
        lihatStatusBuku(b, *this);
    }
};

// Friend function dari class Peminjam
void lihatStatistikPeminjam(const Peminjam& p, const Admin& a) {
    cout << "[Admin Akses Statistik] Total buku dipinjam oleh " << p.nama 
         << ": " << p.totalPinjaman << endl;
}

