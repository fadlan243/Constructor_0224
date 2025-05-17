#include <iostream>
#inlcude <string>
using namespace std;

class mahasiswa{
private :
int nim;
string nama;
public : 
mahasiswa();
mahasiswa(int);
mahasiswa(string);
mahasiswa(int Nim, string iNama);
void cetak();
};

mahasiswa :: mahasiswa(){
    nim = 0;
    nama = "";
}

mahasiswa :: mahasiswa(int iNim){
nim=iNim;
}

mahasiswa :: mahasiswa(string nama){
nama=iNama;
}

mahasiswa :: mahasiswa(int iNim, string iNama){
nim=iNim;
nama=iNama;
}
void mahasiswa::cetak(){
cout<<endl<< "Nim =" <<nim<<endl;
cout << " Nama = " <<nama<endl;
}

int main(){
    mahasiswa mhs1;
    mahasiswa mhs2(20);
    mahasiswa mhs3("Indra");
    mahasiswa mhs4(30, "Fauzan");

    mhs1.cetak();
    mhs2.cetak();
    mhs3.cetak();
    msh4.cetak();

    return 0;
}

// Forward declaration
class Petugas;
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
    int getId() { return id; }

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

    