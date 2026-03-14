#include <iostream>
#include <string.h>
using namespace std;

struct Karyawan{
	int id;
	char nama[50];
};
Karyawan dtkar[50];

struct Barang{
	char nama[50];
	int harga, stok;
};
Barang dtbrg[50];

string keyUsn = "admin";
string keyPsw = "123";

void loginAdmin();
void karyawan();

void mainMenu(){
	system("cls");	
	int pmenu = 0;
	cout << "\n======== WELCOME TO COCOA HEAVEN ========" << endl;
	cout << "1. Login Admin" << endl;
	cout << "2. Karyawan" << endl;
	cout << "3. Keluar" << endl;
	cout << "============================" << endl;
	
	while(pmenu != 1 && pmenu != 2 && pmenu != 3){
	cout << "Masukkan pilihan menu: ";
	cin >> pmenu;
		switch(pmenu){
			case 1:
				loginAdmin();
			break;
			case 2:
				karyawan();
			break;
			case 3:
				cout << "\nSampai jumpa ~" << endl;
				exit(0);
			break;
			default:
				cout << "Menu tidak ada, mohon input menu 1-3" << endl;
				system("pause");
			break;
		}
	}
}

int main(){
	mainMenu();
}

void admTambahKaryawan(){
	int jmlk;
	FILE *fileK;
	fileK = fopen("karyawan.txt", "a");
	
	if(fileK == NULL){
		cout << "File tidak ditemukan!" << endl;
		return;
	}
	
	Karyawan *ptr = dtkar;
	
	cout << "Masukkan jumlah karyawan: ";
	cin >> jmlk;
	
	for(int a=0;a<jmlk;a++){
		cout << "ID karyawan  : ";
		cin >> (ptr+a)->id;
		cout << "Nama karyawan: ";
		cin >> (ptr+a)->nama;
		cout << endl;
	
		fprintf(fileK, "%d %s\n", (ptr+a)->id, (ptr+a)->nama);
	}
	
	fclose(fileK);
	cout << "\nData berhasil disimpan!" << endl;
}

void admLihatKaryawan(){
	FILE *fileK;
	fileK = fopen("karyawan.txt", "r");
	if(fileK == NULL){
		cout << "File tidak ditemukan!" << endl;
		return;
	}
	
	Karyawan *ptr = dtkar;
	
	cout << "\n======== DATA KARYAWAN =======" << endl;
	
	int a = 0;
	while(fscanf(fileK, "%d %s", &(ptr+a)->id, (ptr+a)->nama) != EOF){
		cout << "Karyawan ke-" << (a+1) << endl;
		cout << "ID   : " << (ptr+a)->id << endl;
		cout << "Nama : " << (ptr+a)->nama << endl << endl;
		a++;
	}
	fclose(fileK);	
}

void admCariKaryawan(){
	int idCari;
	bool found = false;
	FILE *fileK;
	fileK = fopen("karyawan.txt", "r");
	if(fileK == NULL){
		cout << "File tidak ditemukan!" << endl;
		return;
	}
	
	cout << "Masukkan ID karyawan yang dicari: ";
	cin >> idCari;
	
	int a = 0;
	while(fscanf(fileK, "%d %s", &dtkar[a].id, dtkar[a].nama) != EOF){
		if(dtkar[a].id == idCari){
			cout << "\nData ditemukan!" << endl;
			cout << "ID   : ";
			cout << dtkar[a].id;
			cout << "\nNama : ";
			cout << dtkar[a].nama;
			cout << "\n\n";
			found = true;
		}
		a++;
	}
	if(!found) cout << "\nData tidak ditemukan!\n";
	
	fclose(fileK);
}

void loginAdmin(){
	string usn, psw;
	int pilihmenu = 0;
	while(usn != keyUsn || psw != keyPsw){
		cout << "Masukkan username Anda: ";
		cin >> usn;
		cout << "Masukkan password Anda: ";
		cin >> psw;
		if(usn != keyUsn || psw != keyPsw){
			cout << "Kamu bukan Admin!" << endl;
	system("pause");
		}
	}
	system("cls");
	cout << "=====================================" << endl;
	cout << "             Halo Admin!" << endl;
	cout << "=====================================" << endl;
	
	while(pilihmenu != 4){
		cout << "1. Tambah data karyawan" << endl;
		cout << "2. Lihat data karyawan" << endl;
		cout << "3. Searching data karyawan" << endl;
		cout << "4. Logout" << endl;
		cout << "=====================================" << endl;
	
		cout << "Pilih menu: ";
		cin >> pilihmenu;
		switch(pilihmenu){
			case 1:
				admTambahKaryawan();
			break;
			case 2:
				admLihatKaryawan();
			break;
			case 3:
				admCariKaryawan();
			break;
			case 4:
				mainMenu();
				return;
			break;
			default:
				cout << "\nMenu tidak ada, mohon input menu 1-4" << endl;
			break;
		}
		
		system("pause");
		system("cls");	
	}
}

//~ menu karyawan
void tambahBarang(){
	int jmlb;
	FILE *fileB;
	fileB = fopen("barang.txt", "a");
	if(fileB == NULL){
		cout << "File tidak ditemukan!" << endl;
		return;
	}
	
	Barang *ptr = dtbrg;
	
	cout << "Masukkan jumlah barang: ";
	cin >> jmlb;
	
	for(int i=0;i<jmlb;i++){
		cout << "Barang ke-" << (i+1) << endl;
		cout << "Nama  : ";
		cin >> (ptr+i)->nama;
		cout << "Harga : ";
		cin >> (ptr+i)->harga;
		cout << "Stok  : ";
		cin >> (ptr+i)->stok;
		cout << endl;
	
		fprintf(fileB, "%s %d %d\n", (ptr+i)->nama, (ptr+i)->harga, (ptr+i)->stok);
	}
	
	fclose(fileB);
	cout << "\nData berhasil disimpan!" << endl;
}

void bubbleSortAsc(){ //asc
	FILE *fileB;
	fileB = fopen("barang.txt", "r");
	if(fileB == NULL){
		cout << "File tidak ditemukan!" << endl;
		return;
	}
	
	Barang *ptr = dtbrg;
	
	int n = 0;
	while(fscanf(fileB, "%s %d %d\n", (ptr+n)->nama, &(ptr+n)->harga, &(ptr+n)->stok) != EOF){
		n++;
	}
	fclose(fileB);
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if ((ptr+j)->harga > (ptr+j+1)->harga) {
				Barang temp = *(ptr+j);
				*(ptr+j) = *(ptr+j+1);
				*(ptr+j+ 1) =  temp;
			}
		}
	}
	
	cout << "\n===== Ascending - Bubble sort =====" << endl;
	for(int i=0;i<n; i++){
		cout << "\nData barang ke-" << (i+1) << endl;
		cout << (ptr+i)->nama << endl;
		cout << (ptr+i)->harga << endl;
		cout << (ptr+i)->stok << endl;
		cout << "-------------------------\n";
	}
}

void quick_sort(int awal, int akhir) { //descending
	int low = awal, high = akhir;
	int pivot = dtbrg[(awal + akhir) / 2].harga;
	do {
		while (dtbrg[low].harga > pivot)
			low++;
		while (dtbrg[high].harga < pivot)
			high--;
		if (low <= high) {
			Barang temp = dtbrg[low];
			dtbrg[low] = dtbrg[high];
			dtbrg[high] = temp;
			
			low++;
			high--;
		}
	} while (low <= high);
	
	if (awal < high)
		quick_sort(awal, high);
	if (low < akhir)
		quick_sort(low, akhir);
}

void quickSortDesc(){
	FILE *fileB;
	fileB = fopen("barang.txt", "r");
	if(fileB == NULL){
		cout << "File tidak ditemukan!" << endl;
		return;
	}
	
	int n = 0;
	while(fscanf(fileB, "%s %d %d", dtbrg[n].nama, &dtbrg[n].harga, &dtbrg[n].stok) != EOF){
		n++;
	}
	fclose(fileB);
	quick_sort(0, n - 1);
	
	cout << "\n===== Descending - Quick sort =====" << endl;
	for(int i=0;i<n; i++){
		cout << "\nData barang ke-" << (i+1) << endl;
		cout << dtbrg[i].nama << endl;
		cout << dtbrg[i].harga << endl;
		cout << dtbrg[i].stok << endl;
		cout << "-------------------------\n";
	}
}

void lihatBarang(){
	int psort = 0;
	cout << "\n1. Ascending" << endl;  //bubble sort
	cout << "2. Descending" << endl; //quick sort
	
	while(psort != 1 && psort != 2){
		cout << "Pilih sorting: ";
		cin >> psort;
		switch(psort){
			case 1:
				bubbleSortAsc();
			break;
			case 2:
				quickSortDesc();
			break;
			default:
				cout << "Pilih 1 atau 2 saja" << endl;
			break;
		}
	}
}

void editBarang(){
	FILE *fileB;
	fileB = fopen("barang.txt", "r");
	if(fileB == NULL){
		cout << "File tidak ditemukan!" << endl;
		return;
	}
	char nmBrgDicari[50];
	bool found = false;
	
	cout << "Masukkan nama barang yang ingin diedit: ";
	cin >> nmBrgDicari;
	
	int n = 0;
	while(fscanf(fileB, "%s %d %d", dtbrg[n].nama, &dtbrg[n].harga, &dtbrg[n].stok) != EOF){
		if(strcmp(dtbrg[n].nama, nmBrgDicari) == 0){
			cout << "\nData ditemukan!" << endl;
			cout << "Nama   : " << dtbrg[n].nama << endl;
			cout << "Harga  : " << dtbrg[n].harga << endl;
			cout << "Stok   : " << dtbrg[n].stok << endl;
			
			cout << "\nMasukkan data baru" << endl;
			cout << "Nama barang  : ";
			cin >> dtbrg[n].nama;
			cout << "Harga barang : ";
			cin >> dtbrg[n].harga;
			cout << "Stok barang  : ";
			cin >> dtbrg[n].stok;
			found = true;
		}
		n++;
	}
	fclose(fileB);
	
	
	if(found){
		FILE *fileW;
		fileW = fopen("barang.txt", "w");
		if(fileW == NULL){
			cout << "File tidak ditemukan!" << endl;
			return;
		}
		
		 for(int i = 0; i < n; i++){
			fprintf(fileW, "%s %d %d\n", dtbrg[i].nama, dtbrg[i].harga, dtbrg[i].stok);
		}
				
		fclose(fileW);
		cout << "\nData berhasil diupdate!\n";
	}else{
		cout << "\nData tidak ditemukan!\n";
	}
}

void sequentialSearch(char brgDicari[50]){ //tanpa sentinel
	FILE *fileB;
	fileB = fopen("barang.txt", "r");
	if(fileB == NULL){
		cout << "File tidak ditemukan!" << endl;
		return;
	}
	
	bool found = false;
	int n = 0;
	while(fscanf(fileB, "%s %d %d", dtbrg[n].nama, &dtbrg[n].harga, &dtbrg[n].stok) != EOF){
		n++;
	}
    fclose(fileB);
	
	for (int i = 0; i < n; i++)
    {
        if (strcmp(dtbrg[i].nama, brgDicari) == 0)
        {
			if(!found) cout << "\nBarang ditemukan!";
			
			cout << "\nNama   : " << dtbrg[i].nama << endl;
			cout << "Harga  : " << dtbrg[i].harga << endl;
			cout << "Stok   : " << dtbrg[i].stok << endl << endl;
            found = true;
        }
    }
    
    if (!found) cout << "Data tidak ditemukan" << endl;   
}

int binarySearchRekursi(int kiri, int kanan, char cari[50]) {
    if(kiri > kanan)
        return -1;

    int tengah = (kiri + kanan) / 2;
    int cmp = strcmp(dtbrg[tengah].nama, cari);

    if(cmp == 0) //ketemu|sama
        return tengah;

    else if(cmp > 0) //cari lebih kecil, cari di kiri
        return binarySearchRekursi(kiri, tengah - 1, cari);

    else // cari lebih besar, cari di kanan
        return binarySearchRekursi(tengah + 1, kanan, cari);
}

void binarySearch(char brgDicari[50]){
	FILE *fileB;
	fileB = fopen("barang.txt", "r");
	
	if(fileB == NULL){
		cout << "File tidak ditemukan!" << endl;
		return;
	}
	
	int n = 0;
	while(fscanf(fileB, "%s %d %d", dtbrg[n].nama, &dtbrg[n].harga, &dtbrg[n].stok) != EOF){
		n++;
	}
	fclose(fileB);
	
	//sort data by nama
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(strcmp(dtbrg[j].nama, dtbrg[j+1].nama) > 0){
                Barang temp = dtbrg[j];
                dtbrg[j] = dtbrg[j+1];
                dtbrg[j+1] = temp;
            }
        }
    }
	
	int hl = binarySearchRekursi(0, n - 1, brgDicari);
    if(hl != -1){
        cout << "\nBarang ditemukan\n";
        cout << "Nama  : " << dtbrg[hl].nama << endl;
        cout << "Harga : " << dtbrg[hl].harga << endl;
        cout << "Stok  : " << dtbrg[hl].stok << endl << endl;
    }else{
        cout << "Data tidak ditemukan" << endl;
	}
}

void cariBarang(){
	int psearch = 0;
	char brgDicari[50];
	cout << "\n1. Sequential Search" << endl;
	cout << "2. Binary Search" << endl;
	
	while(psearch != 1 && psearch != 2){
		cout << "Pilih metode: ";
		cin >> psearch;
		if(psearch != 1 && psearch != 2) cout << "Pilih 1 atau 2 saja" << endl;
	}
	
	cout << "Masukkan nama barang: ";
	cin >> brgDicari;
	if(psearch == 1)
		sequentialSearch(brgDicari);
	else
		binarySearch(brgDicari);
}

void karyawan(){
	int pilihmenu = 0;
	system("cls");
	
	cout << " =====================================" << endl;
	cout << "           Halo Karyawan!" << endl;
	cout << " =====================================" << endl;
	
	while(pilihmenu != 5){
		cout << " 1. Tambah data barang" << endl;
		cout << " 2. Lihat data barang" << endl;
		cout << " 3. Edit data barang" << endl;
		cout << " 4. Cari data barang" << endl;
		cout << " 5. Logout" << endl;
		cout << " =====================================" << endl;
		
		cout << " Pilih menu: ";
		cin >> pilihmenu;
		switch(pilihmenu){
			case 1:
				tambahBarang();
			break;
			case 2:
				lihatBarang();
			break;
			case 3:
				editBarang();
			break;
			case 4:
				cariBarang();
			break;
			case 5:
				mainMenu();
				return;
			break;
			default:
				cout << "\nMenu tidak ada, mohon pilih menu 1-5" << endl;
			break;
		}
	
		system("pause");
		system("cls");	
	}
}
