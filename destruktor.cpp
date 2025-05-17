#include <iostream>
using namespace std;

class angka{
private :
    int *arr;
    int panjang;
public :
    angka(int); // Contructor
    ~angka(); // Destructor
    void cetakData();
    void isiData();
};
//Definisi member Function
angka::angka(int i){ //Constructor
    panjang = i;
    arr = new int [i];
    isiData();
}

angka::~angka(){ //Destructor
    cout<<endl;
    cetakData();
    delete[]arr;
    cout<<"Alamat Array Sudah Dilepaskan"<<endl;
}

void angka::cetak(){
    for(int i=1;1<panjang;i++){
        cout<<i<<" = "<<arr[i]<<endl;
    }
}

void angka::isiData(){
    for(int i=1;i<=panjang;i++){
        cout<<i<<" = ";cont>>Arr[i];
    }
    cout<<endl;
}

int main(){
    angka belajarcpp(3); //constructor Dipanggil
    angka *ptrBelajarcpp = new angka(5); //Constructor Dipanggil
    delete ptrBelajarcpp; //Destructor Dipanggil

    return 0;
}//Destructor Dipanggil

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

    friend class Petugas; // Petugas boleh mengubah status peminjaman
};

