/*
Author      : Ridho Emir Fajar Alam
NPM         : 140810190044
Kelas       : B
Deskripsi   : Program Mengurutkan Angka berdasarkan umur
Tanggal     : 1 Mei 2020
*/
#include <iostream>
#define clear system("cls")
using namespace std;


struct Pasien{
    // data pada elemen queue
    string nama;
    int umur;
    // pointer menunjuk ke elemen berikutnya
    Pasien *next;
};
struct Queue{
    // pointer elemen terdepan dari queue
    Pasien *front;
    // pointer elemen belakang dari queue
    Pasien *back;
};
Queue Q;

void createQueue(Queue &Q);                      //membuat antrian baru
void createElement(Pasien *&new_element);       //pengisian value pada element baru
void enqueue(Queue &Q, Pasien *new_element);    //memasukan data pada urutan terakhir
void dequeue(Queue &Q, Pasien *&result_element);//mengeluarkan data pada urutan pertama
void traversal(Queue Q);   //menampilkan seluruh data
void editQueue(Queue &a, Queue &b, Queue &c);      //mengurutkan antrian menurut umur
void menuAntrianBaru(Queue &a, Queue &b, Queue &c, Pasien* new_element);
void menuDaftarAntrian(Queue a, Queue b, Queue c);
int main(){
    int pilihan;
    Queue lansia,umum,anak;
    Pasien* pasienBaru;
    createQueue(lansia);
    createQueue(umum);
    createQueue(anak);
    a:
    cout <<"=========|StAK|=========\n";
    cout <<"1. Buat Antrian Baru\n";
    cout <<"2. Lihat Daftar Antrian\n";
    cout <<"3. Mengubah Antrian\n";
    cout <<"4. Memanggil Pasien\n";
    cout <<"------------------------------\nPilih (1-4):";cin >> pilihan;
    switch (pilihan)
    {
    case 1:
        clear;
        menuAntrianBaru(lansia,anak,umum,pasienBaru);
        break;
    case 2:
        clear;
        menuDaftarAntrian(lansia,anak,umum);
        break;
    default:
        break;
    }
    goto a;

}
// membuat sebuah queue
void createQueue(Queue &Q){
    Q.front = NULL;
    Q.back = NULL;
}
// membuat elemen baru queue
void createElement(Pasien *&new_element){
    // mengalokasi memori tipe data element
    new_element = NULL;
    new_element = new Pasien;
    cout << "Masukkan Nama Pasien :";getline(cin>>ws, new_element->nama);
    cout << "Masukkan Umur Pasien :";cin >> new_element->umur;
    new_element -> next = NULL;
}
//memasukan elemen ke queue
void enqueue(Queue &Q, Pasien *new_element){
    //kondisi jika queue masih kosong
    if(Q.front == NULL){
        Q.front = new_element;
        Q.back = new_element;
    }
    //kondisi jika queue tidak kosong
    else{
        Q.back -> next = new_element;
        Q.back = new_element;
    }
}
//menghapus elemen dari queue
void dequeue(Queue &Q, Pasien *&result_element){
    //kondisi jika queue kosong
    if(Q.front == NULL){
        cout << "Queue is empty!" << endl;
    }
    //kondisi jika queue tidak kosong
    else{
        result_element = Q.front;
        Q.front = Q.front -> next;
        result_element -> next = NULL;
        cout << "Delete Success!\n";
    }
}
//mencetak elemen/isi sebuah queue
void traversal(Queue Q){
    //kondisi jika queue kosong
    if(Q.front == NULL){
        cout << "Antrian Kosong." << endl;
    }
    //kondisi jika queue tidak kosong
    else{
        Pasien *trav = Q.front;
        cout << "Antrian = [";
        while (trav != NULL){
            cout << trav->nama << ","<<trav->umur;
            trav = trav -> next;
        }
        cout << "]" << endl;
    }
}
void editQueue(Queue &a, Queue &b, Pasien* pCari){
    Pasien *tmp, *tmp1;
    Pasien *pSearch = a.front;
    while(pSearch != a.back){
        if(pSearch == pCari && pSearch == a.front){
            tmp = a.front;
            enqueue(b,tmp);
            a.front = a.front -> next;
            tmp = NULL;
        }else if(pSearch == pCari && pSearch != a.back){
            tmp1 -> next = pSearch -> next;
            tmp = pSearch;
            enqueue(b,tmp);
            tmp = NULL;
        }else if(pSearch == pCari && pSearch == a.back){
            tmp = a.back;
            a.back = tmp1;
            enqueue(b,tmp);
            tmp = NULL;
        }else{
            tmp1 = pSearch;
            pSearch = pSearch -> next;
        }
    }
}
void menueditQueue(Queue &a, Queue &b, Queue &c){
    int pilihan1;
    cout <<"=========|StAK|=========\n";
    cout << "    -Edit Antrian-\n";
    cout <<"1. Poli Lansia\n";
    cout <<"2. Poli Anak\n";
    cout <<"3. Poli Umum\n";
    cout <<"------------------------\n";cout << "Pilih Antrian Asal(1-3) :";cin >> pilihan1;
    switch (pilihan1)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
}
void menuAntrianBaru(Queue &a, Queue &b, Queue &c, Pasien* new_element){
    int pilihan1;
    cout <<"=========|StAK|=========\n";
    cout << "    -Antrian Baru-\n";
    cout <<"1. Poli Lansia\n";
    cout <<"2. Poli Anak\n";
    cout <<"3. Poli Umum\n";
    cout <<"------------------------\n";cout << "Pilih(1-3) :";cin >> pilihan1;
    switch (pilihan1)
    {
    case 1:
        createElement(new_element);
        enqueue(a,new_element);
        cout << "Pasien berhasil ditambahkan dalam Antrian Poli Lansia\n";
        break;
    case 2:
        createElement(new_element);
        enqueue(b,new_element);
        cout << "Pasien berhasil ditambahkan dalam Antrian Poli Anak\n";
        break;
    case 3:
        createElement(new_element);
        enqueue(c,new_element);
        cout << "Pasien berhasil ditambahkan dalam Antrian Poli Anak\n";
        break;
    default:
        cout << "Input yang anda masukan salah!\n";
        break;
    }

}
void menuDaftarAntrian(Queue a, Queue b, Queue c){
    int pilihan2;
    cout <<"=========|StAK|=========\n";
    cout << "   -Daftar Antrian-\n";
    cout <<"1. Poli Lansia\n";
    cout <<"2. Poli Anak\n";
    cout <<"3. Poli Umum\n";
    cout <<"------------------------------\nPilih sesuai kondisi :\n\n";cin>>pilihan2;
    switch (pilihan2)
    {
    case 1:
        traversal(a);
        break;
    case 2:
        traversal(b);
        break;
    case 3:
        traversal(c);
        break;
    default:
        cout << "Input yang anda masukan salah!\n";
        break;
    }
}