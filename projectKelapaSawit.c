/* PROJECT PEMANTAU KEBUN KELAPA SAWIT
 * TEAM A
 * Nama : 1. Satika Ramadhani(1704105010079)
          2. Dina Handayani (1704105010014)
 */
 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

//tipedata struct,agar struct tidak melakukan perulangan
typedef struct {
	float suhu_pohonsawit[500];
	float kelembapan_tanahpohonsawit[500];
	float kadar_Nitrogen[500];
	float kadar_Posfor[500];
	float kadar_Kalium[500];
}Data; 
Data pohon;
int jam = 1; 
char nama_pohonKelapaSawit[100]=""; //nama pohon

//fungsi menuPertama untuk membuat file.
void menuPertama(){ //menu tambah pohon
	FILE *file; 
	printf("Nama Pohon: "); fflush(stdin); //perintah nama pohon
    scanf("%s",nama_pohonKelapaSawit);
	
    printf("\n");
    
	if((file= fopen(nama_pohonKelapaSawit, "r"))== NULL){
    FILE *fileData = fopen("DaftarpohonKelapaSawit.txt", "a"); //buka file DaftarpohonKelapaSawit, a--> apen: tidak terhapus datanya
    	fprintf(fileData, "%s\n",nama_pohonKelapaSawit); 
    	fclose(fileData); //file data ditutup
		
	printf("Pohon berhasil ditambah");
	}
	else{
		printf("Pohon sudah didaftarkan!");
	}
	printf("\n");
}

//fungsi menuKedua untuk menampilkan semua file
void menuKedua(){
	
	system ("type DaftarpohonKelapaSawit.txt"); //perintah untuk cmd

}

//fungsi tampilanData untuk menuKetiga
void tampilanData(){
	int i;
	for(i=1;i<=24;i++){
		printf("Jam %d:00\n", i);
		printf("Suhu Udara pohon sawit       : %f\n", pohon.suhu_pohonsawit[i]);
		printf("Kelembapan Tanah pohon sawit : %f\n", pohon.kelembapan_tanahpohonsawit[i]);
		printf("Kadar N pohon sawit          : %f\n", pohon.kadar_Nitrogen[i]);
		printf("Kadar P pohon sawit          : %f\n", pohon.kadar_Posfor[i]);
		printf("Kadar K pohon sawit          : %f\n", pohon.kadar_Kalium[i]);
		printf("\n");
	}
}

//Fungsi membaca file dan menampilkan
void menuKetiga(){
	FILE *file; //Deklarasi variabel bertipe pointer ke file

		printf("Masukkan Nama Pohon kelapa sawit : ");
		scanf("%s", nama_pohonKelapaSawit);
		printf("\n");
		
			if((file = fopen(nama_pohonKelapaSawit, "r"))== NULL){ //membuka file
				printf("File Tidak Ditemukan\n");
			} 
			else {
			//Membaca dari berkas -> mengcopy data ke variabel
			int x[500]; //untuk jam
				while(fscanf(file, "%d#Suhu:%f#KTanah:%f#KNitrogen:%f#KPospor:%f#KKalium:%f#\n", &x[jam], &pohon.suhu_pohonsawit[jam], &pohon.kelembapan_tanahpohonsawit[jam], &pohon.kadar_Nitrogen[jam], &pohon.kadar_Posfor[jam], &pohon.kadar_Kalium[jam] ) != EOF){
          		jam++;
          		}
          		tampilanData(); //memanggil menu tampilanData
					
    		//Menutup berkas
       		fclose(file); 
					
      		fflush(stdin); //menghapus memori agar buffer tidak penuh
				
			}
}

//fungsi tampilanData menu
void menu(){
	// Variabel tampung pilihan
    char pilihan[4] = "";
	
	do {
  	// Menampilkan menu
    printf("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\ \n");
	printf("|        PROJECT KELAPA SAWIT      | \n");
    printf("|              TEAM A              | \n");
    printf("/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\ \n");
	printf("|              MENU                | \n");
    printf("|  A. Masukkan Data Pohon Baru     | \n");
    printf("|  B. Tampilkan Semua Data Pohon   | \n");
    printf("|  C. Tampilkan Data 1 Pohon       | \n");
  	printf("|  D. Selesai                      | \n");
    printf("\\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/ \n");
    printf("\n");
          
        // Minta pilihan
        printf("\nPilihan: ");
        scanf("%s", pilihan);
    
        // Tampilkan hasil pilihan
        if ( (strcmp(pilihan, "A") == 0) || (strcmp(pilihan, "a") == 0) ) {
        	system("cls");
        	printf("|---Masukkan Data Pohon Baru---| \n");
			menuPertama();
        }
        else if ( (strcmp(pilihan, "B") == 0) || (strcmp(pilihan, "b") == 0) ) {
        	system("cls");
        	printf("|---Tampilkan Semua Data Pohon---| \n");
           	menuKedua();
        }
        else if ( (strcmp(pilihan, "C") == 0) || (strcmp(pilihan, "c") == 0) ) {
        	
        	printf("|---Tampilkan Data 1 Pohon---| \n");
           	menuKetiga();
        }
        else if ( (strcmp(pilihan, "D") == 0) || (strcmp(pilihan, "d") == 0) ) {
            printf("Terima Kasih\n");
        }
        else {
            printf("pilihan tidak dikenal\n");
        }    
    } while(!((strcmp(pilihan, "D") == 0) || (strcmp(pilihan, "d") == 0)));
}

int main(){
	menu();
	
return 0;
}
