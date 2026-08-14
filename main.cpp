#include <iostream>
#include <cstdlib>
#include "jalan.h"
using namespace std;

int main()
{
    //TUBES STD KELOMPOK 10
    //SUTAN RAYA DHARMA NAMANIKA 1301223468
    //M. AULIA PRIADANA SETIAWANKUSUMA 130122307
    list_kota K;
    list_jalan J;
    list_relasi R;
    int pilih;
    createListKota(K);
    createListJalan(J);
    createListRelasi(R);

    mainMenu(K,J,pilih,R);
    return 0;
}
