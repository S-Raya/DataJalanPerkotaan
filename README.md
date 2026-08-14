# Data Jalan Perkotaan

Program pengelolaan data kota dan jalan menggunakan struktur data **Multi Linked List** dengan derajat relasi **M to N**. Dibuat sebagai tugas besar mata kuliah Struktur Data, Jurusan Informatika, Fakultas Informatika, Telkom University (2023).

## Anggota Kelompok 10

| Nama | NIM |
|---|---|
| M. Aulia Priadana | 1301223307 |
| Sutan Raya Dharma | 1301223468 |

## Abstrak

Topik yang diambil adalah data Jalan Perkotaan. Tujuannya adalah menganalisis metode pembuatan database yang fleksibel namun tetap memiliki integritas data yang tinggi. Program ini mampu menyimpan data Kota dan Jalan, serta membangun relasi antara keduanya.

## Deskripsi

Program mengelola data perkotaan dengan fokus pada dua entitas utama: **Kota** dan **Jalan**. Fungsionalitas utamanya meliputi:

- Penambahan data kota dan jalan
- Pengaturan relasi antara kota dan jalan
- Penghapusan data kota, data jalan, beserta relasinya
- Penampilan seluruh data kota dan jalan
- Pencarian kota berdasarkan nama jalan tertentu
- Penampilan jalan yang dimiliki oleh kota tertentu
- Penampilan kota beserta nama jalan berdasarkan tipe jalan tertentu

## Struktur Data

Struktur data yang digunakan adalah **Multi Linked List (M to N)**, terdiri dari dua linked list independen yang saling terhubung melalui *linked list relasi* yang dimiliki oleh linked list *parent* (Kota). Pendekatan ini memungkinkan satu kota memiliki banyak jalan, dan satu jalan (nama+tipe) dapat terhubung ke banyak kota, sambil menjaga integritas data melalui validasi yang dinamis.

### Linked List KOTA
| Atribut | Tipe | Keterangan |
|---|---|---|
| namaKota | string | Nama kota |

### Linked List JALAN
| Atribut | Tipe | Keterangan |
|---|---|---|
| namaJalan | string | Nama jalan |
| tipeJalan | string | Tipe jalan (mis. Satu_Arah, Jalan_Utama) |

## Menu Program

```
+==========MENU============+
|1. Tambah Data Kota       |
|2. Tambah Data Jalan      |
|3. Hapus Data Kota        |
|4. Hapus Data Jalan       |
|5. Buat Relasi            |
|6. Hapus jalan dari kota  |
|7. Lihat List             |
|0. Keluar                 |
+===========================+
```

## Cara Menjalankan

1. Clone repository ini
2. Compile source code program (sesuaikan dengan compiler/bahasa yang digunakan pada project ini)
3. Jalankan program hasil compile
4. Pilih menu sesuai kebutuhan (1–7), atau `0` untuk keluar
5. Buka terminal, ketik `g++ *.cpp -o main` lalu `./main`

## Contoh Penggunaan

**Tambah data kota:**
```
Tambah Data Kota Baru
Nama Kota : Denpasar
*Kota Baru Berhasil Ditambahkan Kedalam List*
```

**Tambah data jalan:**
```
Tambah Data Jalan Baru
Nama Jalan : Gatot_Subroto
Tipe Jalan : Satu_Arah
*Jalan Baru Berhasil Ditambahkan Kedalam List*
```

**Membuat relasi kota-jalan:**
```
Pilih jalan yang ingin di tambahkan
Nama Jalan : Merdeka
Tipe Jalan : Jalan_Utama
Pilih kota sebagai pemilik jalan
Nama Kota : Denpasar
*Kota berhasil dihubungkan ke jalan*
```

**Melihat data setelah beberapa relasi dibuat:**
```
List Kota :
1. Denpasar
     Nangka(Satu_Arah) | Merdeka(Jalan_Utama) | Gatot_Subroto(Jalan_Utama) |
2. Jakarta
     Merdeka(Jalan_Utama) | Gatot_Subroto(Satu_Arah) |
3. Bandung
     Bojongsoang(Jalan_Utama) |
4. Singaraja
     Merdeka(Jalan_Utama) |
5. Badung
     Pulau_Flores(Satu_Arah) |
```

Program juga mendukung pencarian kota berdasarkan nama jalan, menampilkan jalan milik kota tertentu, serta menampilkan kota dan jalan berdasarkan tipe jalan.

## Referensi

Materi mata kuliah Struktur Data terkait Multi Linked List, praktik laboratorium komputer, serta studi sistem database Data Jalan Perkotaan di Indonesia digunakan sebagai dasar perancangan dan validasi struktur data pada project ini.

## Kesimpulan

Database Data Jalan Perkotaan berhasil diimplementasikan menggunakan struktur data Multi Linked List dengan derajat M to N. Program dapat melakukan operasi penambahan data kota, penambahan data jalan, pencarian kota dan jalan, serta penghapusan data kota, data jalan, dan relasi antar keduanya.