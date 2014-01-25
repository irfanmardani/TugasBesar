#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int  carikmp(char *string, char *kata, int *ptr,bool *ketemu, int a,int indeks) {
      int i = 0, j = 0;
      while ((i + j) < strlen(string)) {
              if (kata[j] == string[i + j]) {
                      if (j == (strlen(kata) - 1)) {
                            for(a=0; a<=j ; a++)
                           {   
                               indeks = i+a;
                               printf(" %c DItemukan Pada Indeks = ke-%d \n",kata[a],indeks);
                               *ketemu=true;
                           }
                           return;
                             // printf("%s Berada pada indeks ke : %d\n",kata, i);
                              
                      }
                      j = j + 1;
              } else {
                      i = i + j - ptr[j];
                      if (ptr[j] > -1) {
                              j = ptr[j];
                      } else {
                              j = 0;
                      }
              }
      }
}

/* Mencari kecocokan pada kata dengan pattern */
void carikesamaan(char *kata, int *ptr) {
      int i = 2, j = 0, len = strlen(kata);
      ptr[0] = -1;
      ptr[1] = 0;
      while (i < len) {
              if (kata[i - 1] == kata[j]) {
                      j = j + 1;
                      ptr[i] = j;
                      i = i + 1;
              } else if (j > 0) {
                      j = ptr[j];
              } else {
                      ptr[i] = 0;
                      i = i + 1;
              }
      }
      return;
}


int main(int argc, char *argv[])
{
 int menu=0;
 bool ketemu=false;
 int cariLength;
 int kataLength;
 int i,a;
 int indeks;
 char cari[20];
 char kata[256], string[1024];;
 int *ptr;
 
 do{
    system("cls");
    printf("Menu String Matching\n");
    printf("-------------------------------\n");
    printf("1. Brute Force\n");
    printf("2. Knuth Morris Pratt\n");
    printf("3. Keluar\n");
    printf("-------------------------------\n");
    printf("Masukkan menu pilihan :");
    scanf("%i", &menu);
    switch (menu){
           case 1 :
                system("cls");
                //String
                //char kata[100];
                printf("Masukkan sebuah teks (max 100 digit) = ");
                fflush(stdin);
                gets(kata);

                //Pola yang dicari
                printf("Masukkan pattern = ");
                fflush(stdin);
                gets(cari);

                //strlen = fungsi untuk mendapatkan panjang string
                cariLength = strlen(cari);
                kataLength = strlen(kata); 

                //Mulai Brute Force dalam Pencarian String
  
                for(i=0;i<=kataLength-cariLength;i++)
                {
                   int j=0;
                   while(j<cariLength && kata[i+j] == cari[j])
                   {
                      j++; 
                      if(j >= cariLength)
                      {
                           for(a=0; a<cariLength ; a++)
                           {   
                               indeks = i+a;
                               printf(" %c DItemukan Pada Indeks = ke-%d \n",cari[a],indeks);
                               ketemu=true;
                           }
                      }
                   } 
                }
  
                if(ketemu==false)
                {
                   printf("Pola tidak ditemukan");
                }
                ketemu=false;
                //Akhir Brute Force Pattern Matching
                getch();
                break;
                
           case 2 :
                system("cls");
                printf("String Matching Dengan Algoritma KMP\n");
                printf("--------------------------------------------\n");
                /* Inputan teks */
                printf("Masukan Teks:");
                fflush(stdin);
                fgets(string, 1024, stdin);
                string[strlen(string) - 1] = '\0';

                /* Inputan Pattern*/
                printf("Masukan Pattern:");
                fflush(stdin);
                fgets(kata, 256, stdin);
                kata[strlen(kata) - 1] = '\0';

                ptr = (int *)calloc(1, sizeof(int) * (strlen(kata)));

                /* Mencari kesamaan kata dengan pattern */
                carikesamaan(kata, ptr);
                /* mencari indeks pattern pada teks */
                carikmp(string, kata, ptr,&ketemu,a,indeks);
                if(ketemu==false){
                    printf("\nTidak ditemukan");
                }
                ketemu=false;
                getch();
                break;
           case 3 :
                break;
           default :
                   printf("Menu Pilihan Tidak Terdafratar");
                   getch();
    }
    }while (menu != 3);
  
  system("PAUSE");	
  return 0;
}
