#include "jalan.h"
using namespace std;
void clearScreen(){
    system("cls");
}
void mainMenu(list_kota K,list_jalan J,int pilih,list_relasi R){
    clearScreen();
    cout <<"+===========MENU============+"<<endl;
    cout <<"|1. Tambah Data Kota        |"<<endl;
    cout <<"|2. Tambah Data Jalan       |"<<endl;
    cout <<"|3. Hapus Data Kota         |"<<endl;
    cout <<"|4. Hapus Data Jalan        |"<<endl;
    cout <<"|5. Buat Relasi             |"<<endl;
    cout <<"|6. Hapus jalan dari kota   |"<<endl;
    cout <<"|7. Lihat List              |"<<endl;
    cout <<"|0. Keluar                  |"<<endl;
    cout <<"+===========================+"<<endl;
    cin >> pilih;
    switch (pilih) {
    case 1 :
        tambahKota(K,J,R);
        break;
    case 2 :
        tambahJalan(K,J,R);
        break;
    case 3 :
        hapusKota(K,J,R);
        break;
    case 4 :
        hapusJalan(K,J,R);
        break;
    case 5 :
        buatRelasi(K,J,R);
        break;
    case 6 :
        hapusJalanDariKota(K,J,R);
        break;
    case 7 :
        showList(K,J,pilih,R);
        break;
    case 0 :
        abort();
    }
}
void tambahKota(list_kota &K,list_jalan J, list_relasi R ){//1
    int pilih;
    clearScreen();
    infotype_kota Y;
    cout <<"Tambah Data Kota Baru"<<endl;
    cout <<"Nama Kota : "; cin >> Y.namaKota;
    if (Y.namaKota == "0"){
        mainMenu(K,J,pilih,R);
    }else if (cariKota(K,Y) == NULL){
        insertKota(K,createElmKota(Y));
    }else{
        cout<<"*Kota sudah terdaftar di list kota*"<<endl;
    }
    cout<<"1. Tambah Data Kota"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Pilih : ";cin >> pilih;
    switch (pilih) {
    case 1 :
        tambahKota(K,J,R);
        break;
    }
    mainMenu(K,J,pilih,R);
}
void tambahJalan(list_kota K,list_jalan &J,list_relasi R){//2
    int pilih;
    clearScreen();
    infotype_jalan X;
    cout <<"Tambah Data Jalan Baru"<<endl;
    cout <<"Nama Jalan : "; cin >> X.namaJalan;
    cout <<"Tipe Jalan : "; cin >> X.tipeJalan;
    if (X.namaJalan == "0" || X.tipeJalan == "0" ){
        mainMenu(K,J,pilih,R);
    }else if(cariJalan(J,X) == NULL) {
        insertJalan(J,createElmJalan(X));
    }else{
        cout<<"*Jalan sudah terdaftar di list jalan*"<<endl;
    }
    cout<<"1. Tambah Data Jalan"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Pilih : ";cin >> pilih;
    switch (pilih) {
    case 1 :
        tambahJalan(K,J,R);
        break;
    }
    mainMenu(K,J,pilih,R);
}
void hapusKota(list_kota &K,list_jalan J,list_relasi R){ //3
    clearScreen();
    int pilih;
    infotype_kota Y;
    if (K.first == NULL) {
        cout <<"*Daftar kota kosong*"<<endl;
    }else{
        cout << "Nama kota yang ingin dihapus : "; cin >> Y.namaKota;
        adr_kota P = cariKota(K,Y);
        if (Y.namaKota == "0"){
            mainMenu(K,J,pilih,R);
        }else if (P == NULL){
            clearScreen();
            cout <<"*Nama kota tidak ditemukan*"<<endl;
        }else{
            while (P->relasi != NULL) {
                adr_relasi PR = P->relasi;
                hapusRelasi(R,P,PR);
            }
            if (P == K.first){
                deleteFirstKota(K,P);
                cout<<"*Kota berhasil dihapus*"<<endl;
            }else if (P == K.last){
                deleteLastKota(K,P);
                cout<<"*Kota berhasil dihapus*"<<endl;
            }else{
                deleteAfterKota(K,P);
                cout<<"*Kota berhasil dihapus*"<<endl;
            }
        }
    }
    cout<<"0. Back"<<endl;
    cout<<"Pilih : ";cin>>pilih;
    mainMenu(K,J,pilih,R);
}
void hapusJalan(list_kota K,list_jalan &J,list_relasi R){//4
    clearScreen();
    int pilih;
    infotype_jalan X;
    if (J.first == NULL) {
        cout <<"*Daftar Jalan kosong*"<<endl;
    }else{
        cout << "Nama dan Tipe Jalan yang ingin dihapus : "<<endl;
        cout <<"Nama: ";cin >> X.namaJalan;
        if (X.namaJalan == "0"){
            mainMenu(K,J,pilih,R);
        }
        cout <<"Tipe: ";cin >> X.tipeJalan;
        if (X.namaJalan == "0"){
            mainMenu(K,J,pilih,R);
        }
        adr_jalan Q = cariJalan(J,X);
        if (Q == NULL){
            clearScreen();
            cout <<"Nama Jalan tidak ditemukan :("<<endl;
        }else if (Q == J.first){
            deleteFirstJalan(J,Q);
            cout<<"*Jalan berhasil dihapus*"<<endl;
        }else if (Q == J.last){
            deleteLastJalan(J,Q);
            cout<<"*Jalan berhasil dihapus*"<<endl;
        }else{
            deleteAfterJalan(J,Q);
            cout<<"*Jalan berhasil dihapus*"<<endl;
        }
        adr_kota P = K.first;
        while (P != NULL){
            adr_relasi PR = cariRelasi(R,P,Q);
            if (PR != NULL){
                hapusRelasi(R,P,PR);
            }
                P = P->next;
        }
    }
    cout<<"0. Back"<<endl;
    cout<<"Pilih : ";cin>>pilih;
    mainMenu(K,J,pilih,R);
}
void buatRelasi(list_kota K,list_jalan J,list_relasi R){ //5
    clearScreen();
    int pilih;
    cout <<"1. Relasi jalan ke kota    "<<endl;
    cout <<"2. Relasi kota ke jalan   "<<endl;
    cout <<"0. Kembali   "<<endl;
    cout<<"Pilih : ";cin>>pilih;
    switch (pilih){
    case 1 :
        jalanKeKota(K,J,R);
        break;
    case 2 :
        kotaKeJalan(K,J,R);
        break;
    case 0 :
        mainMenu(K,J,pilih,R);
        break;
    }


}
void hapusJalanDariKota(list_kota &K,list_jalan J,list_relasi &R){//6
    clearScreen();
    int pilih;
    infotype_jalan X;
    infotype_kota Y;
    adr_jalan PJ;
    adr_kota PK;
    adr_relasi PR;
    if (K.first == NULL && J.first == NULL){
        cout<<"*Data kota dan jalan kosong*"<<endl;
    }else{
        cout<<"Hapus jalan dari suatu kota"<<endl;
        cout<<"Nama jalan : ";cin>>X.namaJalan;
        if (X.namaJalan == "0") {
            mainMenu(K,J,pilih,R);
        }
        cout<<"Tipe jalan : ";cin>>X.tipeJalan;
        if (X.tipeJalan == "0") {
            mainMenu(K,J,pilih,R);
        }
        cout<<"Hapus dari kota : ";cin>>Y.namaKota;
        if (Y.namaKota == "0") {
            mainMenu(K,J,pilih,R);
        }
        if (cariJalan(J,X) == NULL){
            cout<<"*Data jalan tidak ditemukan*"<<endl;
        }else if (cariKota(K,Y) == NULL) {
            cout<<"*Data kota tidak ditemukan*"<<endl;
        }else if (PR == NULL){
            cout<<"*Kota "<<Y.namaKota<<" tidak memiliki nama dan tipe jalan tersebut*"<<endl;
        }else{
            PJ = cariJalan(J,X);
            PK = cariKota(K,Y);
            PR = cariRelasi(R,PK,PJ);
            hapusRelasi(R,PK,PR);
            cout<<"*Jalan berhasil dihapus dari kota "<<Y.namaKota<<"*"<<endl;
        }
    }
    cout<<"0. Exit"<<endl;
    cout<<"Pilih : ";
    cin >> pilih;
    mainMenu(K,J,pilih,R);
}
void showList(list_kota K, list_jalan J,int pilih,list_relasi R){//7
    clearScreen();
    cout <<"1. Lihat list kota"<<endl;
    cout <<"2. Lihat list jalan"<<endl;
    cout <<"3. Lihat list kota dengan nama jalan tertentu"<<endl;
    cout <<"4. Lihat list jalan yang dimiliki suatu kota tertentu "<<endl;
    cout <<"5. Lihat nama kota dan nama jalan dengan tipe jalan tertentu"<<endl;
    cout <<"0. Kembali"<<endl;
    cout <<"Pilih : ";cin>>pilih;
    switch (pilih) {
    case 1 :
        showListKota(K,J,R);
        break;
    case 2 :
        showListJalan(K,J,R);
        break;
    case 3 :
        showListKotaDenganJalan(K,J,R);
        break;
    case 4 :
        showListJalanDenganKota(K,J,R);
        break;
    case 5 :
        showKotaJalanDenganTipe(K,J,R);
        break;
    case 0 :
        mainMenu(K,J,pilih,R);
    }

}
void showListKota(list_kota K,list_jalan J,list_relasi R){
    clearScreen();
    int i = 1;
    int pilih;
    if (K.first == NULL){
        cout << "*List Kota Kosong*" <<endl;
    }else{

        cout<<"List Kota : "<<endl;
        adr_kota P = K.first;
        while (P != NULL) {
            cout <<i<<". "<<P ->info.namaKota<<endl;
            adr_relasi Q = P->relasi;
            cout<<"     ";
            while (Q != NULL) {
                cout <<Q->keJalan->info.namaJalan<<"("<<Q->keJalan->info.tipeJalan<<") | ";
                Q = Q->next;
            }
            cout<<endl;
            P = P->next;
            i++;
        }
    }
    cout<<"0. Exit"<<endl;
    cout<<"Pilih : ";
    cin >> pilih;
    mainMenu(K,J,pilih,R);
}
void showListJalan(list_kota K,list_jalan J,list_relasi R){
    clearScreen();
    int i = 1;
    int pilih;
    if (J.first == NULL){
        cout << "*List Jalan Kosong*" <<endl;
    }else{
        cout<<"List Jalan : "<<endl;
        adr_jalan Q = J.first;
        while (Q != NULL) {
            cout <<i<<". "<<Q ->info.namaJalan <<" "<<"("<<Q->info.tipeJalan<<")"<<endl;
            Q = Q->next;
            i++;
        }
    }
    cout<<"0. Exit"<<endl;
    cout<<"Pilih : ";cin >> pilih;
    mainMenu(K,J,pilih,R);
}
void showListKotaDenganJalan(list_kota K,list_jalan J,list_relasi R){
    clearScreen();
    int pilih;
    bool found;
    int i = 0;
    infotype_jalan X;
    adr_kota PK = K.first;


    if (K.first == NULL) {
        cout<<"*List Kota Kosong*"<<endl;
    }else{
        cout <<"Nama Jalan : ";
        cin >>X.namaJalan;
        while (PK != NULL) {
            adr_relasi PR = PK->relasi;
            found = false;
            while (PR != NULL && !found)  {
                if (PR->keJalan->info.namaJalan == X.namaJalan) {
                    found = true;
                }
                PR = PR->next;
            }
            if (found == true) {
                i++;
                cout<<i<<". "<<PK->info.namaKota<<endl;
            }
            PK = PK->next;
        }
        if (i == 0){
            cout<<"*Tidak terdapat kota dengan nama jalan tersebut*"<<endl;
        }
    }
    cout<<"0. Exit"<<endl;
    cout<<"Pilih : ";
    cin >> pilih;
    mainMenu(K,J,pilih,R);
}
void showListJalanDenganKota(list_kota K,list_jalan J, list_relasi R){
    clearScreen();
    int pilih;
    infotype_kota X;
    if (K.first == NULL) {
        cout<<"*List kota kosong*"<<endl;
    }else{
        cout<<"Data jalan dari suatu kota"<<endl;
        cout<<"Nama kota : ";cin>>X.namaKota;
        adr_kota P = cariKota(K,X);
        if (X.namaKota == "0") {
            mainMenu(K,J,pilih,R);
        }else if (P == NULL){
            cout<<"*Nama kota tidak ditemukan*"<<endl;
        }else{
            int i = 1;
            adr_relasi PR = P->relasi;
            if (PR == NULL) {
                cout<<"*List jalan kosong*"<<endl;
            }else{
                cout<<"List jalan dari kota "<<X.namaKota<<" : "<<endl;
                while (PR != NULL) {
                    cout<<i<<". "<<PR->keJalan->info.namaJalan<<" ("<<PR->keJalan->info.tipeJalan<<")"<<endl;
                    i++;
                    PR = PR->next;
                }
            }
        }
    }
    cout<<"0. Exit"<<endl;
    cout<<"Pilih : ";
    cin >> pilih;
    mainMenu(K,J,pilih,R);
}
void showKotaJalanDenganTipe(list_kota K,list_jalan J, list_relasi R){
    clearScreen();
    int pilih;
    int i = 1;
    bool cek = false;
    bool found = false;
    infotype_jalan X;
    if (J.first == NULL) {
        cout<<"*List jalan kosong*"<<endl;
    }else{
        cout<<"Data Kota dan nama jalan dari tipe jalan"<<endl;
        cout<<"Tipe jalan : ";cin>>X.tipeJalan;
        if (X.tipeJalan == "0") {
            mainMenu(K,J,pilih,R);
        }else{
            adr_jalan PJ = J.first;
            while (PJ != NULL){
                if (PJ->info.tipeJalan == X.tipeJalan) {
                    cek = true;
                }
                PJ = PJ->next;
            }
            if (cek == true){
                adr_kota PK = K.first;
                while (PK != NULL){
                    found = false;
                    adr_relasi PR = PK->relasi;
                    while (PR != NULL) {
                        if (PR->keJalan->info.tipeJalan == X.tipeJalan){
                            found = true;
                        }
                        PR = PR->next;
                    }
                    if (found){
                        PR = PK->relasi;
                        cout<<i<<". "<<PK->info.namaKota<<endl;
                        cout<<"     ";
                        while (PR != NULL){
                            if (PR->keJalan->info.tipeJalan == X.tipeJalan){
                                cout<<PR->keJalan->info.namaJalan<<" | ";
                            }
                            PR = PR->next;
                        }
                        i++;
                        cout<<endl;
                    }
                    PK = PK->next;
                }
                if (found == false){
                    cout<<"*Tipe jalan "<<X.tipeJalan<<" tidak terbuhung*"<<endl;
                }
            }else if (cek == false){
                cout<<"*Tipe jalan tidak ditemukan*"<<endl;
            }
        }
    }
    cout<<"0. Exit"<<endl;
    cout<<"Pilih : ";
    cin >> pilih;
    mainMenu(K,J,pilih,R);
}



void jalanKeKota(list_kota &K, list_jalan &J,list_relasi &R){
    clearScreen();
    infotype_jalan jalan;
    infotype_kota kota;
    int pilih;
    cout<<"Pilih jalan yang ingin di tambahkan"<<endl;
    cout<<"Nama Jalan : "; cin >> jalan.namaJalan;
    cout<<"Tipe Jalan : "; cin >> jalan.tipeJalan;
    adr_jalan cariJ = cariJalan(J,jalan);
    if (cariJalan(J,jalan) == NULL){
        cout <<"*Data jalan tidak ditemukan*"<<endl;
    }else{
        cout<<"Pilih kota sebagai pemilik jalan"<<endl;
        cout<<"Nama Kota : "; cin >> kota.namaKota;
        adr_kota Kot = cariKota(K,kota);
        if (cariKota(K,kota) == NULL){
            cout<<"*Data kota tidak ditemukan*"<<endl;
        }else if (cariRelasi(R,Kot,cariJ) == NULL){
            adr_relasi P = createElmRelasi(cariJalan(J,jalan));
            insertRelasi(Kot,P,R);
            cout<<"*Kota berhasil dihubungkan ke jalan*"<<endl;
        }else{
            cout<<"*Jalan sudah terhubung ke kota "<<kota.namaKota<<"*"<<endl;
        }
    }
    cout<<"1. Sambungkan jalan ke kota"<<endl;
    cout<<"0. Menu"<<endl;
    cin >> pilih;
    switch (pilih) {
    case 1 :
        jalanKeKota(K,J,R);
        break;
    case 0 :
        mainMenu(K,J,pilih,R);
        break;

    }

}
void kotaKeJalan(list_kota &K, list_jalan &J,list_relasi &R){
    clearScreen();
    infotype_jalan jalan;
    infotype_kota kota;
    int pilih;
    cout<<"Pilih kota yang ingin di tambahkan"<<endl;
    cout<<"Nama kota : "; cin >> kota.namaKota;
    adr_kota Kot = cariKota(K,kota);
    if (cariKota(K,kota) == NULL){
        cout <<"*Data kota tidak ditemukan*"<<endl;
    }else{
        cout<<"*Data kota ditemukan*"<<endl;
        cout<<"Pilih jalan untuk dimiliki kota"<<endl;
        cout<<"Nama jalan : "; cin >> jalan.namaJalan;
        cout<<"Tipe jalan : "; cin >> jalan.tipeJalan;
        adr_jalan Jal = cariJalan(J,jalan);
        if (cariJalan(J,jalan) == NULL){
            cout<<"*Data jalan tidak ditemukan*"<<endl;
        }else{
            adr_relasi P = createElmRelasi(cariJalan(J,jalan));
            insertRelasi(Kot,P,R);
            cout<<"*Jalan berhasil dihubungkan ke kota*"<<endl;
        }
    }
    cout<<"1. Sambungkan jalan ke kota"<<endl;
    cout<<"0. Menu"<<endl;
    cin >> pilih;
    switch (pilih) {
    case 1 :
        kotaKeJalan(K,J,R);
        break;
    case 0 :
        mainMenu(K,J,pilih,R);
        break;

    }
}





void createListRelasi(list_relasi &R){
    R.first = NULL;

}
adr_relasi createElmRelasi(adr_jalan P){
    adr_relasi R = new elm_relasi;
    R -> keJalan = P;
    R->next = NULL;

    return R;
}
void insertRelasi(adr_kota &K, adr_relasi &P,list_relasi &R){

    if (K->relasi == NULL) {
        R.first = P;
    }else{
        P->next = K->relasi;
        R.first = P;
    }
    K->relasi = R.first;
}
void deleteFirstRelasi(adr_kota &K,list_relasi &R,adr_relasi &PR){
    if (K->relasi == NULL){
        PR = NULL;
    }else{
        PR = K->relasi;
        K->relasi = PR->next;
        PR->next = NULL;
        PR->keJalan = NULL;
    }

}
void deleteLastRelasi(adr_kota &K,list_relasi &R,adr_relasi &PR){
    adr_relasi Q;
    if (K->relasi == NULL) {
        PR = NULL;
    }else if (K->relasi->next == NULL){
        PR = K->relasi;
        PR->keJalan = NULL;
        K->relasi = NULL;
    }else{
        Q = K->relasi;
        while (Q->next != PR) {
            Q = Q->next;
        }
        Q->next = NULL;
        PR->keJalan = NULL;
        PR->next = NULL;
    }
}
void deleteAfterRelasi(adr_kota &K,list_relasi &R,adr_relasi &PR){
    if (K->relasi == NULL){
        PR = NULL;
    }else{
        adr_relasi Q = K->relasi;
        while (Q->next != PR){
            Q = Q->next;
        }
        Q->next = PR->next;
        PR->next = NULL;
        PR->keJalan = NULL;
    }
}
adr_relasi cariRelasi(list_relasi &R,adr_kota K,adr_jalan J){
    adr_relasi P = K->relasi;
    while (P != NULL) {
        if (P->keJalan == J){
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void hapusRelasi(list_relasi &R,adr_kota P,adr_relasi &PR){
    if (PR == P->relasi){
        deleteFirstRelasi(P,R,PR);
    }else if (PR->next == NULL){
        deleteLastRelasi(P,R,PR);
    }else{
        deleteAfterRelasi(P,R,PR);
    }
}

void createListKota(list_kota &K){
    K.first = NULL;
    K.first = NULL;
}
adr_kota createElmKota(infotype_kota Y){
    adr_kota P = new elm_kota;
    P->info.namaKota = Y.namaKota;
    P->next = NULL;
    P->prev = NULL;
    P->relasi = NULL;
    return P;
}
void insertKota(list_kota &K, adr_kota P){
    if (K.first == NULL) { //insert first
        K.first = P;
        K.last = P;
    }else{ //insert last
        K.last->next = P;
        P->prev= K.last;
        K.last = P;
    }
    cout <<"*Kota Baru Berhasil Ditambahkan Kedalam List*"<<endl;
}
adr_kota cariKota(list_kota K, infotype_kota kota){
    adr_kota P = K.first;
    while (P != NULL){
        if (P->info.namaKota == kota.namaKota) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void deleteLastKota(list_kota &K, adr_kota &P){
    if (K.first == NULL) {
        P = NULL;
    }else if (K.first == K.last){
        P = K.last;
        K.first = NULL;
        K.last = NULL;
    }else{
        P = K.last;
        K.last = P->prev;
        K.last->next = NULL;
        P->prev = NULL;
    }
}
void deleteFirstKota(list_kota &K, adr_kota &P){
    if (K.first == NULL){
        P = NULL;
    }else if (K.first == K.last){
        P = K.first;
        K.first = NULL;
        K.last = NULL;
    }else{
        P = K.first;
        K.first = P->next;
        P->next = NULL;
        P->prev = NULL;
    }
}
void deleteAfterKota(list_kota &K,adr_kota &P){
    if (K.first == NULL){
        P = NULL;
    }else{
        P->prev->next = P->next;
        P->next->prev = P->prev;
        P->next = NULL;
        P->prev = NULL;
    }
}



void createListJalan(list_jalan &J){
    J.first = NULL;
    J.last = NULL;
}
adr_jalan createElmJalan(infotype_jalan X){
    adr_jalan Q = new elm_jalan;
    Q->info.namaJalan = X.namaJalan;
    Q->info.tipeJalan = X.tipeJalan;
    Q->next = NULL;
    Q->prev = NULL;
    return Q;
}
void insertJalan(list_jalan &J, adr_jalan Q){
    if (J.first == NULL) { //insert first
        J.first = Q;
        J.last = Q;
    }else{ //insert last
        J.last->next = Q;
        Q->prev= J.last;
        J.last = Q;
    }
    cout <<"*Jalan Baru Berhasil Ditambahkan Kedalam List*"<<endl;
}
void deleteLastJalan(list_jalan &J, adr_jalan &Q){
    if (J.first == NULL) {
        Q = NULL;
    }else if (J.first == J.last){
        Q = J.last;
        J.first = NULL;
        J.last = NULL;
    }else{
        Q = J.last;
        J.last = Q->prev;
        J.last->next = NULL;
        Q->prev = NULL;
    }
}
void deleteFirstJalan(list_jalan &J,adr_jalan &Q){
    if (J.first == NULL){
        Q = NULL;
    }else if (J.first == J.last){
        Q = J.first;
        J.first = NULL;
        J.last = NULL;
    }else{
        Q = J.first;
        J.first = Q->next;
        Q->next = NULL;
        Q->prev = NULL;
    }
}
void deleteAfterJalan(list_jalan &J, adr_jalan &Q){
    if (J.first == NULL){
        Q = NULL;
    }else{
        Q->prev->next = Q->next;
        Q->next->prev = Q->prev;
        Q->next = NULL;
        Q->prev = NULL;
    }
}
adr_jalan cariJalan(list_jalan J, infotype_jalan jalan){
    adr_jalan Q = J.first;
    while (Q != NULL){
        if (Q->info.namaJalan == jalan.namaJalan && Q->info.tipeJalan == jalan.tipeJalan) {
            return Q;
        }
        Q = Q->next;
    }
    return NULL;
}



