#include <iostream>
#include <iomanip>
#include <windows.h>
#define clear system("cls")
#define pause system("pause")
#define sleepy Sleep(250)
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
void panggilQueue(Queue &Q,Pasien *result_element);//mengeluarkan data pada urutan pertama
void traversal(Queue Q);   //menampilkan seluruh data
void editQueue(Queue &asal, Queue &tujuan, Pasien* &pCari, string &antrian);      //mengurutkan antrian menurut umur
void menuAntrianBaru(Queue &a, Queue &b, Queue &c, Pasien* new_element);
void menuDaftarAntrian(Queue a, Queue b, Queue c);
void menueditQueue(Queue &a, Queue &b, Queue &c, Pasien* &pCari);
void menuPanggilQueue(Queue &a, Queue &b, Queue &c, Pasien *result_element);
void buktiAntrian(string antrian, Pasien *&new_element);
int main(){
    int pilihan;
    char pilihan2;
    Queue lansia,umum,anak;
    Pasien* pasienBaru, *pasienPanggil;
    createQueue(lansia);
    createQueue(umum);
    createQueue(anak);
    do{
    clear;
    cout <<"=========|StAK|=========\n";
    cout <<"1. Buat Antrian Baru\n";
    cout <<"2. Lihat Daftar Antrian\n";
    cout <<"3. Mengubah Antrian\n";
    cout <<"4. Memanggil Pasien\n";
    cout <<"5. Exit program\n";
    cout <<"------------------------------\nPilih (1-5):";cin >> pilihan;
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
    case 3:
        clear;
        menueditQueue(lansia,anak,umum, pasienBaru);
        break;
    case 4:
        clear;
        menuPanggilQueue(lansia,anak,umum,pasienPanggil);
        break;
    case 5:
        cout << "Terimakasi telah menggunakan layanan StAK \n";
        exit(0);
        break;
    default:
        cout << "Input yang anda masukkan salah!\n";
        break;
    }
    cout << "Ingin melanjutkan program (Y/N)? ";cin >> pilihan2;
    }while(pilihan2 == 'Y' || pilihan2 == 'y');

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
        for(int i=0; i<35; i++){
            cout <<"=";
        }
        cout << "\n|            Nama            |Umur|\n";
        for(int i=0; i<35; i++){
            cout <<"-";
        }
        cout << endl;
        while (trav != NULL){
            cout << setw(29)<< left << "| " + trav -> nama  << "|"<< setw(4) << left << trav -> umur << "|"<<endl;
            trav = trav -> next;
        }
        for(int i=0; i<35; i++){
            cout <<"=";
        }
        cout << endl;
    }
}
void editQueue(Queue &asal, Queue &tujuan, Pasien* &pCari, string &antrian){
    Pasien *tmp, *tmp1;
    Pasien *pSearch = asal.front;
    while(tmp1 != asal.back){
        if(pSearch -> nama == pCari -> nama && pSearch ->umur == pCari -> umur && pSearch == asal.front){
            tmp = new Pasien;
            tmp -> nama = asal.front -> nama;
            tmp -> umur = asal.front -> umur;
            tmp -> next = NULL;
            enqueue(tujuan,tmp);
            asal.front = asal.front -> next;
            cout << "Pemindahan antrian telah berhasil di lakukan\n";
            cout << "Bukti Antrian Sedang Diproses";
            buktiAntrian(antrian,tmp);
            tmp = NULL;
            break;
        }else if(pSearch -> nama == pCari -> nama && pSearch ->umur == pCari -> umur && pSearch != asal.back){
            tmp = NULL;
            tmp = new Pasien;
            tmp -> nama = pSearch -> nama;
            tmp -> umur = pSearch -> umur;
            tmp -> next = NULL;
            tmp1 -> next = pSearch -> next;
            enqueue(tujuan,tmp);
            tmp = NULL;
            cout << "Pemindahan antrian telah berhasil di lakukan\n";
            break;
        }else if(pSearch -> nama == pCari -> nama && pSearch ->umur == pCari -> umur && pSearch == asal.back){
            tmp = NULL;
            tmp = new Pasien;
            tmp -> nama = asal.back -> nama;
            tmp -> umur = asal.back -> umur;
            tmp -> next = NULL;
            asal.back = tmp1;
            
            enqueue(tujuan,tmp);
            tmp = NULL;
            cout << "Pemindahan antrian telah berhasil di lakukan\n";
            break;
        }else{
            if(pSearch == asal.back){
                cout <<"Nama yang dicari tidak ditemukan dalam antrian ini !\n";
                break;
            }else{
                tmp1 = pSearch;
                pSearch = pSearch -> next;
            } 
        }
    }
}
void buktiAntrian(string antrian, Pasien *&new_element){
    Pasien *pBaru;
    pBaru = new Pasien;
    pBaru -> nama = new_element -> nama;
    pBaru -> umur = new_element -> umur;
    for(int i=0;i<4;i++){
        sleepy;
        cout << ".";
    }
    cout << endl;
    pause;
    clear;
    for(int i=0; i<35; i++){
            cout <<"=";
    }
    cout << endl;
    if(antrian == "Poli Lansia"){
        cout << setw(35)<< "|   Bukti Antrian  Poli Lansia    |\n";
    }else{
        cout << setw(35)<< "|     Bukti Antrian " + antrian + "     |\n";
    }
    for(int i=0; i<35; i++){
        cout <<"-";
    }
    cout << endl;
    cout << setw(34) << left << "|Nama : " + pBaru -> nama << "|" << endl;
    cout << "|Umur : " << setw(26) << left << pBaru -> umur << "|" << endl;
    for(int i=0; i<35; i++){
        cout <<"=";
    }
    cout << endl << "Harap Bukti Antrian Disimpan dengan baik !\n";
}
void panggilQueue(Queue &Q,Pasien *result_element){
    //kondisi jika queue kosong
    if(Q.front == NULL){
        cout << "Queue is empty!" << endl;
    }
    //kondisi jika queue tidak kosong
    else{
        result_element = Q.front;
        Q.front = Q.front -> next;
        cout<<result_element->nama<<endl;
        result_element -> next = NULL;
        cout << "Pasien Terpanggil!\n";
    }
}
void menueditQueue(Queue &a, Queue &b, Queue &c, Pasien* &pCari){
    int pilihan1,pilihan2;
    string antrian;
    cout <<"=========|StAK|=========\n";
    cout << "    -Edit Antrian-\n";
    cout <<"1. Poli Lansia\n";
    cout <<"2. Poli Anak\n";
    cout <<"3. Poli Umum\n";
    cout <<"------------------------\n";cout << "Pilih Antrian Asal(1-3) :";cin >> pilihan1;
    switch (pilihan1)
    {
    case 1:
        cout <<"=========|StAK|=========\n";
        cout << "    -Edit Antrian-\n";
        cout <<"1. Poli Anak\n";
        cout <<"2. Poli Umum\n";
        cout <<"------------------------\n";cout << "Pilih Antrian Yang dituju(1-3) :";cin >> pilihan2;
        switch (pilihan2)
        {
        case 1:
            clear;
            pCari=NULL;
            pCari = new Pasien;
            cout << "----|Pemindahan antrian dari Poli lansia -> Poli Anak|----\n";
            cout << "Masukkan Data Diri Pasien yang akan dipindahkan\n";
            cout << "Masukkan Nama Pasien :";getline(cin>>ws, pCari->nama);
            cout << "Masukkan Umur Pasien :";cin >> pCari->umur;
            antrian = "Poli Anak";
            editQueue(a,b,pCari,antrian);
            break;
        case 2:
            clear;
            pCari = NULL;
            pCari = new Pasien;
            cout << "----|Pemindahan antrian dari Poli lansia -> Poli Umum|----\n";
            cout << "Masukkan Data Diri Pasien yang akan dipindahkan\n";
            cout << "Masukkan Nama Pasien :";getline(cin>>ws, pCari->nama);
            cout << "Masukkan Umur Pasien :";cin >> pCari->umur;
            antrian = "Poli Umum";
            editQueue(a,c,pCari,antrian);
            break;
        default:
            cout << "Input yang anda masukkan salah!\n";
            break;
        }
        break;
    case 2:
        cout <<"=========|StAK|=========\n";
        cout << "    -Edit Antrian-\n";
        cout <<"1. Poli Lansia\n";
        cout <<"2. Poli Umum\n";
        cout <<"------------------------\n";cout << "Pilih Antrian Yang dituju(1-3) :";cin >> pilihan2;
        switch (pilihan2)
        {
        case 1:
            clear;
            pCari=NULL;
            pCari = new Pasien;
            cout << "----|Pemindahan antrian dari Poli Anak -> Poli Lansia|----\n";
            cout << "Masukkan Data Diri Pasien yang akan dipindahkan\n";
            cout << "Masukkan Nama Pasien :";getline(cin>>ws, pCari->nama);
            cout << "Masukkan Umur Pasien :";cin >> pCari->umur;
            antrian = "Poli Lansia";
            editQueue(b,a,pCari,antrian);
            break;
        case 2:
            clear;
            pCari=NULL;
            pCari = new Pasien;
            cout << "----|Pemindahan antrian dari Poli Anak -> Poli Umum|----\n";
            cout << "Masukkan Data Diri Pasien yang akan dipindahkan\n";
            cout << "Masukkan Nama Pasien :";getline(cin>>ws, pCari->nama);
            cout << "Masukkan Umur Pasien :";cin >> pCari->umur;
            antrian = "Poli Umum";
            editQueue(b,c,pCari,antrian);
            break;
        default:
            cout << "Input yang anda masukkan salah!\n";
            break;
        }
        break;
    case 3:
        cout <<"=========|StAK|=========\n";
        cout << "    -Edit Antrian-\n";
        cout <<"1. Poli Lansia\n";
        cout <<"2. Poli Anak\n";
        cout <<"------------------------\n";cout << "Pilih Antrian Yang dituju(1-3) :";cin >> pilihan2;
        switch (pilihan2)
        {
        case 1:
            clear;
            pCari=NULL;
            pCari = new Pasien;
            cout << "----|Pemindahan antrian dari Poli Umum -> Poli Lansia|----\n";
            cout << "Masukkan Data Diri Pasien yang akan dipindahkan\n";
            cout << "Masukkan Nama Pasien :";getline(cin>>ws, pCari->nama);
            cout << "Masukkan Umur Pasien :";cin >> pCari->umur;
            antrian = "Poli Lansia";
            editQueue(c,a,pCari,antrian);
            break;
        case 2:
            clear;
            pCari=NULL;
            pCari = new Pasien;
            cout << "----|Pemindahan antrian dari Poli Umum -> Poli Anak|----\n";
            cout << "Masukkan Data Diri Pasien yang akan dipindahkan\n";
            cout << "Masukkan Nama Pasien :";getline(cin>>ws, pCari->nama);
            cout << "Masukkan Umur Pasien :";cin >> pCari->umur;
            antrian = "Poli Anak";
            editQueue(c,b,pCari,antrian);
            break;
        default:
            cout << "Input yang anda masukkan salah!\n";
            break;
        }
        break;
    default:
        cout << "Input yang anda masukkan salah!\n";
        break;
    }
}
void menuAntrianBaru(Queue &a, Queue &b, Queue &c, Pasien* new_element){
    int pilihan1;
    string antrian;
    cout <<"=========|StAK|=========\n";
    cout << "    -Antrian Baru-\n";
    cout <<"1. Poli Lansia\n";
    cout <<"2. Poli Anak\n";
    cout <<"3. Poli Umum\n";
    cout <<"------------------------\n";cout << "Pilih(1-3) :";cin >> pilihan1;
    switch (pilihan1)
    {
    case 1:
        antrian = "Poli Lansia";
        createElement(new_element);
        if(new_element -> umur >= 0){
            enqueue(a,new_element);
            cout << "Pasien berhasil ditambahkan dalam Antrian Poli Lansia\n";
            cout << "Bukti Antrian Sedang Diproses";
            buktiAntrian(antrian,new_element);
            break;
        }else{
            cout << "Gagal Menambah Antrian, silahkan masukkan umur >= 0\n";
            break;
        }
    case 2:
        antrian = "Poli Anak";
        createElement(new_element);
        enqueue(b,new_element);
        cout << "Pasien berhasil ditambahkan dalam Antrian Poli Anak\n";
        cout << "Bukti Antrian Sedang Diproses";
        buktiAntrian(antrian,new_element);
        break;
    case 3:
        antrian = "Poli Umum";
        createElement(new_element);
        enqueue(c,new_element);
        cout << "Pasien berhasil ditambahkan dalam Antrian Poli Umum\n";
        cout << "Bukti Antrian Sedang Diproses";
        buktiAntrian(antrian,new_element);
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
    cout <<"------------------------------\nPilih sesuai kondisi :";cin>>pilihan2;
    switch (pilihan2)
    {
    case 1:
        clear;
        cout << "====|Daftar Pasien Antrian Poli Lansia|====\n";
        traversal(a);
        break;
    case 2:
        clear;
        cout << "====|Daftar Pasien Antrian Poli Anak|====\n";
        traversal(b);
        break;
    case 3:
        clear;
        cout << "====|Daftar Pasien Antrian Poli Umum|====\n";
        traversal(c);
        break;
    default:
        cout << "Input yang anda masukan salah!\n";
        break;
    }
}
void menuPanggilQueue(Queue &a, Queue &b, Queue &c, Pasien *result_element){
     int pilihan1;
    cout <<"=========|StAK|=========\n";
    cout << "    -Panggil Antrian-\n";
    cout <<"1. Poli Lansia\n";
    cout <<"2. Poli Anak\n";  
    cout <<"3. Poli Umum\n";
    cout <<"------------------------\n";cout << "Pilih Antrian (1-3) :";cin >> pilihan1;
    switch (pilihan1)
    {
    case 1:
        panggilQueue(a,result_element);
        break;

    case 2:
        panggilQueue(b,result_element);
        break;

    case 3:
        panggilQueue(c,result_element);
        break;

    default:
        cout << "Input yang anda masukkan salah!\n";
        break;
    }

}