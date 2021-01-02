#include <locale.h> //t�rk�e karakter i��n
#include <stdio.h> //klasik input output elemanlar� i�in
#include <stdlib.h> //malloc kullan�rsak diye
#include <string.h> //stringler ile alakl� i�lemler icin
#include <conio.h> //renk vermek i�in
struct tumveri{
 	char isim[30];
 	int no;
	int bm101_not[2];
	int bm101_dev;
	int bm103_not[2];
	int bm103_dev;
	int mat199_not[2];
	int mat199_dev;
}ogrenci[10];
/*girislerde tan�mlanan sifreler ile girildi�inde ogretmen oldu�u belli olacak
o alana girince istedi�ini yapabilecek zaten*/

/////////////////////////*** Prototik Tan�mlamalar� ***////////////////////////////
void idari_giris();
void satir_bas();//her eylemden sonra esitlik basmak(sat�r atlamak) icin
void ana_menu();
int idari(); //burda s�k�nt� var, bir k�s�mdan sonras�n� basm�yor.
void ogretmen_giris();
void ogrenci_giris();
void ogretmen_uraz();
void ogretmen_oktay();
void ogretmen_serife();
///////////////////////////////////////////////////////////////
/* FONKS�YONLAR*/
int main(){
	system("COLOR 30");
	setlocale(LC_ALL, "Turkish"); //T�rk�e karakter sorunu i�in ekledi�imiz kod
	//printf("%s", og1.isim);

	ana_menu();

	return 0;
}
void idari_giris(){
	system("CLS");
	char ikullanici[]="Serif1";
	char isifre[]="123456";
	char kullanci[10];
	char sifre[10];
	printf(" �dari Girisi yap�n�z\n Kullan�c� ad�n�z:");
	scanf("%s", &kullanci);
	printf("\n Sifreniz:");
	scanf("%s", &sifre);
	if (!strcmp(kullanci, ikullanici)){
		if(!strcmp(sifre, isifre)){
			satir_bas();
			printf("Giris basarili\n");
			idari();
		}
	}else{
			printf("Giris basarisiz, \n Ana men�ye geri d�n�l�yor...");
			getchar();
			ana_menu();		
		}
}
void ana_menu(){
	system("CLS");
	int secim; //men�de ki secim icin al�nacak karakter i�in
	printf("\n1.�dari giri�\n2.��retmen giri�i\n3.��renci giri�i(not ve devams�zl�k sorgulama)\n\t");
	secim= getchar(); //inputu yakalamak i�in, secim char de�il ama getchardan dolay� char olarak yakalar
	satir_bas();
	switch(secim){
		case '1':
			printf(" �dari Hesab�n�z ile Giris Yap�n�z\n");
			satir_bas();
			idari_giris();
		break;
		case '2':
			printf(" ��retmen Hesab�n�z ile Giris Yap�n�z");
			satir_bas();
			ogretmen_giris();
		break;
		case '3':
			printf(" ��renci numaran�z ile sorgulayabilirsiniz ");
			satir_bas();
			ogrenci_giris();
		break;
		default:
			ana_menu();
	}
}
int idari(){
	int i;
	int c=1;
	int ii;
	int sira;
	int sec1;
	int secim2;
//	satir_bas();
	printf("1.Ogrenci Kay�tlar�n� yapmak icin\n2.Ogrenci kayd� silmek icin\n3.Kay�t listesini g�r�nt�lemek i�in\n4.Ana men�ye d�nmek i�in\n Se�iminiz:");
	scanf("%d", &secim2);
	satir_bas();
	if(secim2 == 1){
		for(i=0; i<10;i++){
			printf("'�sim_Soyisim' �eklinde giriniz..\n");
			printf("%d. ogrencinin ismini giriniz:", i+1);
			scanf("%s", &ogrenci[i].isim);
			printf("%d. ogrencinin no'sunu giriniz:", i+1);
			scanf("%d", &ogrenci[i].no);
			satir_bas();
		}
		getchar();
		getchar();
		idari();
	}else if(secim2 == 2){
		for(ii=0;ii<10;ii++){	
			printf("%d.S�ra:  %d'Nolu %s\n", ii+1, ogrenci[ii].no, ogrenci[ii].isim);
		}
		satir_bas();
		printf("Silmek istedi�iniz kayd�n s�ra numaras�n�n bir eksi�ini giriniz:");
		scanf("%d", &sira);
		printf("\n�sleniyor...");
		getchar();
		strcpy(ogrenci[sira].isim,"XXXXXX");
		ogrenci[sira].no=0000;
		printf("Baska kay�t silmek istiyor musunuz?\n E--1 ��kmak istiyorsan�z herhangi bir say�ya bas�n�z:\t");
		scanf("%d", &sec1);
		if(sec1 == 1){
			while(c==1){
				satir_bas();
				printf("Silmek istedi�iniz kayd�n s�ra numaras�n� giriniz:");
				scanf("%d", &sira);
				printf("\n �sleniyor...");
				getchar();
				strcpy(ogrenci[sira].isim,"XXXXXX");
				ogrenci[sira].no=0000;
				printf("Baska kay�t silmek istiyor musunuz?\n E--1 ��kmak istiyorsan�z herhangi bir tu�a bas�n�z");
				scanf("%d", &sec1);
				if(sec1==1){c=1;}else{c=0;}
			}
			idari();
		}else{
			idari();
			}
		}else if(secim2==3){
			system("CLS");
			satir_bas();
			for(ii=0;ii<10;ii++){	
			printf("%d.S�ra:  %d'Nolu %s\n", ii+1, ogrenci[ii].no, ogrenci[ii].isim);
			}
			getchar();
			satir_bas();
			idari();
		}else if(secim2 ==4){
			ana_menu();
		}
}
void satir_bas(){
	printf("\n===================================\n");
}
void ogrenci_giris(){
//	char ikullanici[]="Serif1";
//	char isifre[]="123456";
//	char kullanci[10];
//	char sifre[10];
	int i;
	int secim;
	int cmp;
	printf(" ��renci Giri�i yap�n�z\n ��renci Numaran�z:");
	scanf("%d", &cmp);
	for(i=0;i<10;i++){
		if(ogrenci[i].no == cmp){
			printf("\nMerhaba, %s\n BM103 Vize Notunuz:%d, Final Notunuz:%d,\n Ders notunuz:%lf , Devams�zl���n�z:%d\n===========\n",ogrenci[i].isim, ogrenci[i].bm103_not[0], ogrenci[i].bm103_not[1], ogrenci[i].bm103_not[0]*0.4+ogrenci[i].bm103_not[1]*0.6, ogrenci[i].bm103_dev);
			printf(" BM101 Vize Notunuz:%d, Final Notunuz:%d,\n Ders notunuz:%lf, Devams�zl���n�z:%d\n===========\n", ogrenci[i].bm101_not[0],ogrenci[i].bm101_not[1], ogrenci[i].bm101_not[0]*0.4+ogrenci[i].bm101_not[1]*0.6, ogrenci[i].bm101_dev);
			printf(" MAT199 Vize Notunuz:%d, Final Notunuz:%d,\n Ders notunuz:%lf , Devams�zl���n�z:%d\n=======================================\n", ogrenci[i].mat199_not[0], ogrenci[i].mat199_not[1], ogrenci[i].mat199_not[0]*0.4+ogrenci[i].mat199_not[1]*0.6, ogrenci[i].mat199_dev);				
			}
	}
				printf("Ba�ka ��renci giri�i yapmak i�in 1'e bas�n�z, ana men�ye ge�mek i�in herhangi bir tu�a bas�n�z.");
				scanf("%d", &secim);
				if(secim == 1){
					ogrenci_giris();
				}else{
					ana_menu();
				}
}
void ogretmen_uraz(){
	system("CLS");
	int i, secim, secim2;
	printf("Devams�zl�k bilgilerini girmek i�in 0 \n Not bilgilerini girmek i�in 1");
	scanf("%d", &secim);
	if(secim == 0 ){
		for(i=0;i<10;i++){
			printf("%d 'nolu %s i�in\n ", ogrenci[i].no, ogrenci[i].isim);
			printf("Devams�zl�k: ");
			scanf("%d", &ogrenci[i].bm103_dev);
		}
		satir_bas();
		printf("Ana men�ye d�nmek i�in 0 \n Kendi b�l�m�n�ze d�nmek i�in 1:\t");
		scanf("%d", &secim2);
		if(secim2 == 0){
			ana_menu();
		}else if(secim2==1){
			ogretmen_uraz();
		}
			
	}else if(secim == 1){
			for(i=0;i<10;i++){
				printf("%d 'nolu %s i�in\n ", ogrenci[i].no, ogrenci[i].isim);
				printf("Vize notu:");
				scanf("%d", &ogrenci[i].bm103_not[0]);
				printf("Final notu:");
				scanf("%d", &ogrenci[i].bm103_not[1]);
			}
		satir_bas();
		printf("Ana men�ye d�nmek i�in 0 \n Kendi b�l�m�n�ze d�nmek i�in 1:\t");
		scanf("%d", &secim2);
		if(secim2 == 0){
			ana_menu();
		}else if(secim2==1){
			ogretmen_uraz();
		}
	}
}
void ogretmen_oktay(){
	system("CLS");
	int i, secim, secim2;
	printf("Devams�zl�k bilgilerini girmek i�in 0 \n Not bilgilerini girmek i�in 1");
	scanf("%d", &secim);
	if(secim == 0 ){
		for(i=0;i<10;i++){
			printf("%d 'nolu %s i�in\n ", ogrenci[i].no, ogrenci[i].isim);
			printf("Devams�zl�k: ");
			scanf("%d", &ogrenci[i].bm101_dev);
		}
		satir_bas();
		printf("Ana men�ye d�nmek i�in 0 \n Kendi b�l�m�n�ze d�nmek i�in 1:\t");
		scanf("%d", &secim2);
		if(secim2 == 0){
			ana_menu();
		}else if(secim2==1){
			ogretmen_oktay();
		}
	}else if(secim == 1){
			for(i=0;i<10;i++){
				printf("%d 'nolu %s i�in\n ", ogrenci[i].no, ogrenci[i].isim);
				printf("Vize notu:");
				scanf("%d", &ogrenci[i].bm101_not[0]);
				printf("Final notu:");
				scanf("%d", &ogrenci[i].bm101_not[1]);
			}
		satir_bas();
		printf("Ana men�ye d�nmek i�in 0 \n Kendi b�l�m�n�ze d�nmek i�in 1:\t");
		scanf("%d", &secim2);
		if(secim2 == 0){
			ana_menu();
		}else if(secim2==1){
			ogretmen_oktay();
		}
	}
}
void ogretmen_serife(){
	system("CLS");
	int i, secim, secim2;
	printf("Devams�zl�k bilgilerini girmek i�in 0 \n Not bilgilerini girmek i�in 1");
	scanf("%d", &secim);
	if(secim == 0 ){
		for(i=0;i<10;i++){
			printf("%d 'nolu %s i�in\n ", ogrenci[i].no, ogrenci[i].isim);
			printf("Devams�zl�k: ");
			scanf("%d", &ogrenci[i].mat199_dev);
		}
		satir_bas();
		printf("Ana men�ye d�nmek i�in 0 \n Kendi b�l�m�n�ze d�nmek i�in 1:\t");
		scanf("%d", &secim2);
		if(secim2 == 0){
			ana_menu();
		}else if(secim2==1){
			ogretmen_serife();
		}
	}else if(secim == 1){
			for(i=0;i<10;i++){
				printf("%d 'nolu %s i�in\n ", ogrenci[i].no, ogrenci[i].isim);
				printf("Vize notu:");
				scanf("%d", &ogrenci[i].mat199_not[0]);
				printf("Final notu:");
				scanf("%d", &ogrenci[i].mat199_not[1]);
			}
		satir_bas();
		printf("Ana men�ye d�nmek i�in 0 \n Kendi b�l�m�n�ze d�nmek i�in 1:\t");
		scanf("%d", &secim2);
		if(secim2 == 0){
			ana_menu();
		}else if(secim2==1){
			ogretmen_serife();
		}
	}
}
void ogretmen_giris(){
	system("CLS");
	char ikullanici1[]="Uraz1";
	char isifre1[]="123456";
	char ikullanici2[]="Oktay1";
	char isifre2[]="123456"; 
	char ikullanici3[]="Serife1";
	char isifre3[]="123456";
	char kullanci[10];
	char sifre[10];
	printf(" Ogretmen kimliginiz ile giris yap�n�z : \n Kullan�c� ad�n�z:");
	scanf("%s", &kullanci);
	printf("\n Sifreniz:");
	scanf("%s", &sifre);
	if (!strcmp(kullanci, ikullanici1)){
		if(!strcmp(sifre, isifre1)){
			satir_bas();
			printf("Hosgeldiniz Uraz Hocam, \n Alperen Kula'ya AA vermek ister misiniz?\n");
			ogretmen_uraz();
			//anamenu();
			}else{
			printf("Giris basarisiz, \n Ana men�ye geri d�n�l�yor...");
			getchar();
			ana_menu();		
		}
	}
	else if(!strcmp(kullanci, ikullanici2)){
			if(!strcmp(sifre, isifre2)){
			satir_bas();
			printf("Hosgeldiniz Oktay Hocam, \n Mustafa Mahir K�l�n�'a AA vermek istermisiniz?\n");
			ogretmen_oktay();
			//anamenu();
			}else{
			printf("Giris basarisiz, \n Ana men�ye geri d�n�l�yor...");
			getchar();
			ana_menu();		
		}
	}	
	else if(!strcmp(kullanci, ikullanici3)){
			if(!strcmp(sifre, isifre3)){
			satir_bas();
			printf("Hosgeldiniz Serife Hocam, \n Muhammed Ali Erg�l'� b�rakmak istermisiniz?\n");
			ogretmen_serife();
			//anamenu();
			}else{
			printf("Giris basarisiz, \n Ana men�ye geri d�n�l�yor...");
			getchar();
			ana_menu();		
		}
	}
}
