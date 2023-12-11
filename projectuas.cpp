#include <iostream>

#include <string>

using namespace std;

string user, pw, username = "admin", password = "123";
int pil;
int b, c, d, e;
int jmlBuku;
char status;
string namaPjm, alamatPjm, tglPjm, tglBalik;
int umurPjm, bukuPjm;


struct buku {
    int kodeBuku;
    string judul;
    int stock;
};

struct newUser {
    int kodeUser;
    string nama;
    int umur;
};

struct pinjam {
    int kp;
    int kb;
};


buku slotBuku[100];
newUser slotUser[100];
pinjam batasPinjam[100];


void garis();
void menu();
void inputBuku();
void library();
void daftar();
void data();
void peminjaman();
void rekap();
void keluar();
void pesan(string login) {
    cout << "Status Login Anda : " << login << endl;
}


int main () {
    c = 0;
    e = 0;
    
    garis();
    cout << "\n\tSelamat Datang di Program Perpustakaan Ceria" << endl;
    garis();
    cout << endl;
    int i = 1;
    string loginSuccess;
    do {

        cout << "Silahkan Login Terlebih Dahulu" << endl;
        cout << "Username : ";
        cin >> user;
        cout << "Password : ";
        cin >> pw;
    
        if (user == username && pw == password) {
            cout << "Anda Berhasil Login" << endl;
            loginSuccess = "berhasil";
            i = 4;
            pesan("Berhasil");
        } else {
            cout << "Username atau Password Salah!\n";
            i++;      
        }
    } while(i <= 3);

    if(loginSuccess != "berhasil") {
        garis();
        cout << "\n\t\tAnda Telah Gagal Login 3x" << endl;
        cout << "\t\tTunggu Beberapa Saat Lagi\n" << endl;
        pesan("Gagal");
        garis();
        
        return 0;
    }

    menu();
    
    return 0;
}

void garis() {
    for(int i = 0; i < 60; i++) {
        cout << "=";
    }
}

void menu() {
    garis();
    cout << "\n\t\tPilihan Menu" << endl;
    garis();
    cout << endl;

    cout << " 1. Input Buku Baru" << endl;
    cout << " 2. Daftar Buku" << endl;
    cout << " 3. Pendaftaran Anggota" << endl;
    cout << " 4. Data Anggota" << endl;
    cout << " 5. Peminjaman Buku" << endl;
    cout << " 6. Struk Peminjaman Buku" << endl;
    cout << " 7. Keluar" << endl;

    cout << "Masukkan Pilihan : ";
    cin >> pil;

    system("cls");
    switch(pil) {
        case 1 : 
            inputBuku();
            break;
        case 2 : 
            library();
            break;
        case 3 : 
            daftar();
        case 4 : 
            data();
            break;
        case 5 : 
            peminjaman();
            break;
        case 6 : 
            rekap();
            break;
        case 7 : 
            keluar();
            break;
        default : 
            cout << "Pilihan Tidak Tersedia" << endl;
            system("pause");
            system("cls");
            menu();

    }
}

void inputBuku() {
    cout << "Masukkan Banyak Buku yang ingin di Tambahkan : ";
    cin >> jmlBuku;
    cin.ignore();

    for(b = 0; b < jmlBuku; b++) {

        cout << "Masukkan Data Buku ke-" << b + 1 << endl;
        cout << "Kode Buku : ";
        cin >> slotBuku[b].kodeBuku;
        cin.ignore();
        cout << "Judul Buku : " ;
        getline(cin, (slotBuku[b].judul));
        cout << "Jumlah Buku : ";
        cin >> slotBuku[b].stock;
        cout << endl;
    }
   system("cls");
   menu();
}

void library() {
    
    garis();
    cout << "\n\t\t\tDaftar Buku" << endl;
    garis();

    cout << "\n\tKode Buku        Judul Buku      Jumlah Buku\n";
    
    for (b = 0; b < jmlBuku; b++) { //nilai awal 0, kurang dari nilai input a, bertambah sampai max nilai a
        cout << "\t" << slotBuku[b].kodeBuku << "              " << slotBuku[b].judul << "            " << slotBuku[b].stock << "            " << endl;
    }

    cout << endl;
    menu();
}

void daftar() {
    garis();
    cout << "\n\t\tPendaftaran Anggota" << endl;
    garis();
    cout << endl;

    for (d = c; d < c + 1; d++) {
        cout << "Kode Anggota(angka) : ";
        cin >> slotUser[d].kodeUser;
        cin.ignore();
        cout << "Nama : ";
        getline(cin, slotUser[d].nama);
        cout << "Umur : ";
        cin >> slotUser[d].umur;
    }
    c++;
     
    
    cout << " Ingin Menginputkan Data Lagi?(y/n) : ";
    cin >> status;

    if (status == 'Y' || status == 'y') {
        daftar();
    } else {
        system("cls");
        menu();
    }
}

void data() {
    garis();
    cout << "\n\t\t\tData Anggota" << endl;
    garis();
    cout << endl;

    cout << "\tKode Peminjaman          Nama            Umur  \n";

    for (d = 0; d < c; d++) {
        cout << " \t\t" << slotUser[d].kodeUser << "                " << slotUser[d].nama << "             " << slotUser[d].umur << "  " << endl;
    }
    
    menu();
}

void peminjaman() {
    garis();
    cout << "\n\t\t\tPeminjaman Buku" << endl;
    garis();
    cout << "\nNama Depan Peminjam : ";
    cin >> namaPjm;
    cout << "Umur Peminjam : ";
    cin >> umurPjm;
    cout << "Alamat Peminjam : ";
    cin >> alamatPjm;
    cout << "Kode Buku : ";
    cin >> bukuPjm;
    
    system("cls");

    bool bukuDitemukan = true;

    for(b = 0; b < jmlBuku; b++) {
        if(bukuPjm == slotBuku[b].kodeBuku) {
            cout << "Judul Buku : " << slotBuku[b].judul << endl;
            bukuDitemukan = false;
            break;
        }
    }
    if (bukuDitemukan) {
        cout << "Buku Tidak Ditemukan" << endl;
    }
    
    cout << "Tanggal Peminjaman (DD/MM/YYYY) : ";
    cin >> tglPjm;
    cout << "Tanggal Pengembalian (DD/MM/YYYY) : ";
    cin >> tglBalik;
    cout << endl;

    cout << " Ingin Menginputkan Data Lagi?(y/n) : ";
    cin >> status;

    if (status == 'Y' || status == 'y') {
        daftar();
    } else {
        system("cls");
        menu();
    }
}

void rekap() {
    cout << "Nama : " << namaPjm << endl;
    cout << "Umur : " << umurPjm << endl;
    cout << "Alamat : " << alamatPjm << endl;
    cout << "Tanggal Peminjaman : " << tglPjm << endl;
    cout << "Tanggal Pengembalian : " << tglBalik << endl;
}

void keluar() {
    cout << "Terima Kasih Telah Menggunakan Aplikasi Ini^^" << endl;
}