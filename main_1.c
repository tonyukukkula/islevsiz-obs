#include <locale.h> //türkçe karakter içün
#include <stdio.h> //klasik input output elemanlarý için
#include <stdlib.h> //malloc kullanýrsak diye
#include <string.h> //stringler ile alaklý iþlemler icin
#include <conio.h> //renk vermek için
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
/*girislerde tanýmlanan sifreler ile girildiðinde ogretmen olduðu belli olacak
o alana girince istediðini yapabilecek zaten*/

/////////////////////////*** Prototik Tanýmlamalarý ***////////////////////////////
void idari_giris();
void satir_bas();//her eylemden sonra esitlik basmak(satýr atlamak) icin
void ana_menu();
int idari(); //burda sýkýntý var, bir kýsýmdan sonrasýný basmýyor.
void ogretmen_giris();
void ogrenci_giris();
void ogretmen_uraz();
void ogretmen_oktay();
void ogretmen_serife();
///////////////////////////////////////////////////////////////
/* FONKSÝYONLAR*/
int main(){
	system("COLOR 30");
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter sorunu için eklediðimiz kod
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
	printf(" Ýdari Girisi yapýnýz\n Kullanýcý adýnýz:");
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
			printf("Giris basarisiz, \n Ana menüye geri dönülüyor...");
			getchar();
			ana_menu();		
		}
}
void ana_menu(){
	system("CLS");
	int secim; //menüde ki secim icin alýnacak karakter için
	printf("\n1.Ýdari giriþ\n2.Öðretmen giriþi\n3.Öðrenci giriþi(not ve devamsýzlýk sorgulama)\n\t");
	secim= getchar(); //inputu yakalamak için, secim char deðil ama getchardan dolayý char olarak yakalar
	satir_bas();
	switch(secim){
		case '1':
			printf(" Ýdari Hesabýnýz ile Giris Yapýnýz\n");
			satir_bas();
			idari_giris();
		break;
		case '2':
			printf(" Öðretmen Hesabýnýz ile Giris Yapýnýz");
			satir_bas();
			ogretmen_giris();
		break;
		case '3':
			printf(" Öðrenci numaranýz ile sorgulayabilirsiniz ");
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
	printf("1.Ogrenci Kayýtlarýný yapmak icin\n2.Ogrenci kaydý silmek icin\n3.Kayýt listesini görüntülemek için\n4.Ana menüye dönmek için\n Seçiminiz:");
	scanf("%d", &secim2);
	satir_bas();
	if(secim2 == 1){
		for(i=0; i<10;i++){
			printf("'Ýsim_Soyisim' Þeklinde giriniz..\n");
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
			printf("%d.Sýra:  %d'Nolu %s\n", ii+1, ogrenci[ii].no, ogrenci[ii].isim);
		}
		satir_bas();
		printf("Silmek istediðiniz kaydýn sýra numarasýnýn bir eksiðini giriniz:");
		scanf("%d", &sira);
		printf("\nÝsleniyor...");
		getchar();
		strcpy(ogrenci[sira].isim,"XXXXXX");
		ogrenci[sira].no=0000;
		printf("Baska kayýt silmek istiyor musunuz?\n E--1 Çýkmak istiyorsanýz herhangi bir sayýya basýnýz:\t");
		scanf("%d", &sec1);
		if(sec1 == 1){
			while(c==1){
				satir_bas();
				printf("Silmek istediðiniz kaydýn sýra numarasýný giriniz:");
				scanf("%d", &sira);
				printf("\n Ýsleniyor...");
				getchar();
				strcpy(ogrenci[sira].isim,"XXXXXX");
				ogrenci[sira].no=0000;
				printf("Baska kayýt silmek istiyor musunuz?\n E--1 Çýkmak istiyorsanýz herhangi bir tuþa basýnýz");
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
			printf("%d.Sýra:  %d'Nolu %s\n", ii+1, ogrenci[ii].no, ogrenci[ii].isim);
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
	printf(" Öðrenci Giriþi yapýnýz\n Öðrenci Numaranýz:");
	scanf("%d", &cmp);
	for(i=0;i<10;i++){
		if(ogrenci[i].no == cmp){
			printf("\nMerhaba, %s\n BM103 Vize Notunuz:%d, Final Notunuz:%d,\n Ders notunuz:%lf , Devamsýzlýðýnýz:%d\n===========\n",ogrenci[i].isim, ogrenci[i].bm103_not[0], ogrenci[i].bm103_not[1], ogrenci[i].bm103_not[0]*0.4+ogrenci[i].bm103_not[1]*0.6, ogrenci[i].bm103_dev);
			printf(" BM101 Vize Notunuz:%d, Final Notunuz:%d,\n Ders notunuz:%lf, Devamsýzlýðýnýz:%d\n===========\n", ogrenci[i].bm101_not[0],ogrenci[i].bm101_not[1], ogrenci[i].bm101_not[0]*0.4+ogrenci[i].bm101_not[1]*0.6, ogrenci[i].bm101_dev);
			printf(" MAT199 Vize Notunuz:%d, Final Notunuz:%d,\n Ders notunuz:%lf , Devamsýzlýðýnýz:%d\n=======================================\n", ogrenci[i].mat199_not[0], ogrenci[i].mat199_not[1], ogrenci[i].mat199_not[0]*0.4+ogrenci[i].mat199_not[1]*0.6, ogrenci[i].mat199_dev);				
			}
	}
				printf("Baþka öðrenci giriþi yapmak için 1'e basýnýz, ana menüye geçmek için herhangi bir tuþa basýnýz.");
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
	printf("Devamsýzlýk bilgilerini girmek için 0 \n Not bilgilerini girmek için 1");
	scanf("%d", &secim);
	if(secim == 0 ){
		for(i=0;i<10;i++){
			printf("%d 'nolu %s için\n ", ogrenci[i].no, ogrenci[i].isim);
			printf("Devamsýzlýk: ");
			scanf("%d", &ogrenci[i].bm103_dev);
		}
		satir_bas();
		printf("Ana menüye dönmek için 0 \n Kendi bölümünüze dönmek için 1:\t");
		scanf("%d", &secim2);
		if(secim2 == 0){
			ana_menu();
		}else if(secim2==1){
			ogretmen_uraz();
		}
			
	}else if(secim == 1){
			for(i=0;i<10;i++){
				printf("%d 'nolu %s için\n ", ogrenci[i].no, ogrenci[i].isim);
				printf("Vize notu:");
				scanf("%d", &ogrenci[i].bm103_not[0]);
				printf("Final notu:");
				scanf("%d", &ogrenci[i].bm103_not[1]);
			}
		satir_bas();
		printf("Ana menüye dönmek için 0 \n Kendi bölümünüze dönmek için 1:\t");
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
	printf("Devamsýzlýk bilgilerini girmek için 0 \n Not bilgilerini girmek için 1");
	scanf("%d", &secim);
	if(secim == 0 ){
		for(i=0;i<10;i++){
			printf("%d 'nolu %s için\n ", ogrenci[i].no, ogrenci[i].isim);
			printf("Devamsýzlýk: ");
			scanf("%d", &ogrenci[i].bm101_dev);
		}
		satir_bas();
		printf("Ana menüye dönmek için 0 \n Kendi bölümünüze dönmek için 1:\t");
		scanf("%d", &secim2);
		if(secim2 == 0){
			ana_menu();
		}else if(secim2==1){
			ogretmen_oktay();
		}
	}else if(secim == 1){
			for(i=0;i<10;i++){
				printf("%d 'nolu %s için\n ", ogrenci[i].no, ogrenci[i].isim);
				printf("Vize notu:");
				scanf("%d", &ogrenci[i].bm101_not[0]);
				printf("Final notu:");
				scanf("%d", &ogrenci[i].bm101_not[1]);
			}
		satir_bas();
		printf("Ana menüye dönmek için 0 \n Kendi bölümünüze dönmek için 1:\t");
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
	printf("Devamsýzlýk bilgilerini girmek için 0 \n Not bilgilerini girmek için 1");
	scanf("%d", &secim);
	if(secim == 0 ){
		for(i=0;i<10;i++){
			printf("%d 'nolu %s için\n ", ogrenci[i].no, ogrenci[i].isim);
			printf("Devamsýzlýk: ");
			scanf("%d", &ogrenci[i].mat199_dev);
		}
		satir_bas();
		printf("Ana menüye dönmek için 0 \n Kendi bölümünüze dönmek için 1:\t");
		scanf("%d", &secim2);
		if(secim2 == 0){
			ana_menu();
		}else if(secim2==1){
			ogretmen_serife();
		}
	}else if(secim == 1){
			for(i=0;i<10;i++){
				printf("%d 'nolu %s için\n ", ogrenci[i].no, ogrenci[i].isim);
				printf("Vize notu:");
				scanf("%d", &ogrenci[i].mat199_not[0]);
				printf("Final notu:");
				scanf("%d", &ogrenci[i].mat199_not[1]);
			}
		satir_bas();
		printf("Ana menüye dönmek için 0 \n Kendi bölümünüze dönmek için 1:\t");
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
	printf(" Ogretmen kimliginiz ile giris yapýnýz : \n Kullanýcý adýnýz:");
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
			printf("Giris basarisiz, \n Ana menüye geri dönülüyor...");
			getchar();
			ana_menu();		
		}
	}
	else if(!strcmp(kullanci, ikullanici2)){
			if(!strcmp(sifre, isifre2)){
			satir_bas();
			printf("Hosgeldiniz Oktay Hocam, \n Mustafa Mahir Kýlýnç'a AA vermek istermisiniz?\n");
			ogretmen_oktay();
			//anamenu();
			}else{
			printf("Giris basarisiz, \n Ana menüye geri dönülüyor...");
			getchar();
			ana_menu();		
		}
	}	
	else if(!strcmp(kullanci, ikullanici3)){
			if(!strcmp(sifre, isifre3)){
			satir_bas();
			printf("Hosgeldiniz Serife Hocam, \n Muhammed Ali Ergül'ü býrakmak istermisiniz?\n");
			ogretmen_serife();
			//anamenu();
			}else{
			printf("Giris basarisiz, \n Ana menüye geri dönülüyor...");
			getchar();
			ana_menu();		
		}
	}
}
