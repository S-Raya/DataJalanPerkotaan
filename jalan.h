#ifndef JALAN_H_INCLUDED
#define JALAN_H_INCLUDED
#include <iostream>
#include <cstdlib>

using namespace std;

struct Kota {
    string namaKota;
};
struct Jalan {
    string namaJalan, tipeJalan;
};
typedef struct Kota infotype_kota;
typedef struct Jalan infotype_jalan;
typedef struct elm_kota *adr_kota;
typedef struct elm_jalan *adr_jalan;
typedef struct elm_relasi *adr_relasi;
struct list_jalan{
    adr_jalan first;
    adr_jalan last;
};
struct list_kota{
    adr_kota first;
    adr_kota last;
};
struct list_relasi{
    adr_relasi first;
};
struct elm_kota {
    infotype_kota info;
    adr_kota next;
    adr_kota prev;
    adr_relasi relasi;
};
struct elm_relasi{
    adr_jalan keJalan;
    adr_relasi next;
};
struct elm_jalan {
    infotype_jalan info;
    adr_jalan next;
    adr_jalan prev;
};
//MENU
void clearScreen();//prosedur tambahan untuk clear screen (hanyak untuk estetika)
void mainMenu(list_kota K,list_jalan J,int pilih,list_relasi R);//tampilan main menu
void tambahKota(list_kota &K,list_jalan J,list_relasi R);//prosedur untuk menambahkan kota baru ke list
void tambahJalan(list_kota K,list_jalan &J,list_relasi R);//prosedur untuk menambahkan jalan baru ke list
void hapusKota(list_kota &K,list_jalan J,list_relasi R);//prosedur untuk menghapus kota dari list (daftar relasi kota ke jalan ikut kehapus)
void hapusJalan(list_kota K,list_jalan &J,list_relasi R);//prosedur untuk menghapus jalan dari list (relasi kota yang memiliki relasi ke jalan yang ingin dihapus akan kehapus)
void buatRelasi(list_kota K,list_jalan J,list_relasi R);//prosedur untuk menyambungkan atau membuat relasi dari kota ke jalan
void hapusJalanDariKota(list_kota &K,list_jalan J,list_relasi &R);//prosedur untuk menghapus jalan dari suatu kota
void showList(list_kota K, list_jalan J,int pilih,list_relasi R);//tampilan menu show

//SHOW
void showListKota(list_kota K,list_jalan J,list_relasi R);//prosedur untuk menampilkan list kota
void showListJalan(list_kota K,list_jalan J,list_relasi R);//prosedur untuk menampilkan list jalan
void showListKotaDenganJalan(list_kota K,list_jalan J,list_relasi R);//prosedur untuk menampilkan list kota berdasarkan jalan
void showListJalanDenganKota(list_kota K,list_jalan J, list_relasi R);//prosedur untuk menampilkan list jalan dari suatu kota
void showKotaJalanDenganTipe(list_kota K,list_jalan J, list_relasi R);//prosedur untuk menampilkan nama kota dan list jalan dari suatu kota tersebut berdasarkan tipe jalan


//RELASI
void createListRelasi(list_relasi &R);//prosedur untuk membuat list relasi
adr_relasi createElmRelasi(adr_jalan P);//prosedur untuk membuat elemen relasi
void insertRelasi(adr_kota &K,adr_relasi &P,list_relasi &R);//prosedur untuk menambahkan relasi (insert first)
void hapusRelasi(list_relasi &R,adr_kota P,adr_relasi &PR);//prosedur untuk menentukan hapus relasi (first,after, atau last)
void deleteFirstRelasi(adr_kota &K,list_relasi &R,adr_relasi &PR);//prosedur untuk delete first dari list relasi
void deleteLastRelasi(adr_kota &K,list_relasi &R,adr_relasi &PR);//prosedur untuk delete last dari list relasi
void deleteAfterRelasi(adr_kota &K,list_relasi &R,adr_relasi &PR);//prosedur untuk delete after dari list relasi
void jalanKeKota(list_kota &K, list_jalan &J,list_relasi &R);//prosedur untuk menghubungkan jalan ke kota
void kotaKeJalan(list_kota &K, list_jalan &J,list_relasi &R);//prosedur untuk menghubungkan kota ke jalan
adr_relasi cariRelasi(list_relasi &R,adr_kota K,adr_jalan J);//prosedur untuk mencari adr relasi

//KOTA
void createListKota(list_kota &K);//prosedur untuk membuat list kota
adr_kota createElmKota(infotype_kota Y);//prosedur untuk membuat elemen kota
void insertKota(list_kota &K, adr_kota P); //prosedur untuk menambahkan kota (insert last)
void deleteLastKota(list_kota &K, adr_kota &P);//prosedur untuk menghapus kota (delete last)
void deleteFirstKota(list_kota &K, adr_kota &P);//prosedur untuk menghapus kota (delete first)
void deleteAfterKota(list_kota &K,adr_kota &P);//prosedur untuk menghapus kota (delete after)
adr_kota cariKota(list_kota K, infotype_kota kota);//prosedur untuk mencari adr kota

//JALAN
void createListJalan(list_jalan &J);//prosedur untuk membuat list jalan
adr_jalan createElmJalan(infotype_jalan X);//prosedur untuk membuat elemen jalan
void insertJalan(list_jalan &J, adr_jalan Q);//prosedur untuk menambahkan jalan (insert last)
void deleteLastJalan(list_jalan &J, adr_jalan &Q);//prosedur untuk menghapus jalan (delete last)
void deleteFirstJalan(list_jalan &J,adr_jalan &Q);//prosedur untuk menghapus jalan (delete first)
void deleteAfterJalan(list_jalan &J, adr_jalan &Q);//prosedur untuk menghapus jalan (delete after)
adr_jalan cariJalan(list_jalan J, infotype_jalan X);//prosedur untuk mencari adr jalan





#endif // JALAN_H_INCLUDED
