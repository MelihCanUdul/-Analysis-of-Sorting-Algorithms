// CombSort.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<time.h>
#include <ctime>
#include <cmath>
using namespace std;
double sabit=1.24733;

//counting
void yazdir(int a[], int boyut) {
	for (int i = 0; i < boyut;  i++ ) 
	cout << a[i] << " ";
	cout << endl;
}

void SaymaSiralamasi(int dizi[], int boyut) {
	int i, j, k;
	int index = 0;
	int min, max;
 
	min = max = dizi[0];
	for(i = 1; i < boyut; i++) {
		min = (dizi[i] < min) ? dizi[i] : min;
		max = (dizi[i] > max) ? dizi[i] : max;
	}
 
	k = max - min + 1;
	
	int *B = new int [k]; 
	for(i = 0; i < k; i++) 
		B[i] = 0;

	for(i = 0; i < boyut; i++)
		B[dizi[i] - min]++;
	for(i = min; i <= max; i++) 
		for(j = 0; j < B[i - min]; j++)
			dizi[index++] = i;
 
	yazdir(dizi,boyut);

	delete [] B;
}


//kokteyl
void CocktailSort(int a[], int n) 
{   //Swap islemi yaılacaktir.
	//baslangic ve son degerler tanimlanmistir.
	bool durum = true; 
	int baslangic = 0; 
	int son = n - 1; 
    while (durum) { 
		durum = false; 
		//Soldan sağa doğru sayma işlemi yapılır.Küçük olan başa gelir.
	
		for (int i = baslangic; i < son; ++i) { 
			if (a[i] > a[i + 1]) { 
				swap(a[i], a[i + 1]); 
				durum = true; 
			} 
		} 
	//Eğer hiçbir şey taşınmazsa dizi sıralanır.
		if (!durum) 
			break; 
		//Eğer bu işlem yapılmamışsa başlangıç değerinin tektar kullanılabilmesi için sıfırladık.
		 
		durum = false; 

	--son; 

		for (int i = son - 1; i >= baslangic; --i) { 
			if (a[i] > a[i + 1]) { 
				swap(a[i], a[i + 1]); 
				durum= true; 
			} 
		}
		++baslangic; } 
} 
// Yazdırma işlemi yapılır.
void diziyiyazdir(int a[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout<<a[i]<<" ";
	   cout<<endl;
} 


int _tmain(int argc, _TCHAR* argv[])
{
	cout<<" 1-COMB SORT  \n 2-COUNTING SORT\n 3-KOKTEYL SORT \n 4-KIYASLAMA YAPMA \n SECIMINIZ : ";
	int secim;
	cin>>secim;
	if (secim==1)
	{
	int boyut;
	int *dizi;
	cout << "SABIT  SAYI   :" << sabit << "\n";
	cout << "Dizinin Boyutunu Giriniz:";
	cin >> boyut;
	cout << "\n";
	srand(time(NULL));
	dizi = new int[boyut]; 
	clock_t time_req;
	time_req = clock();
	//POİNTER DİZİ OLUSTURMA 
	 //POİNTER DİZİYE RASTGELE ELEMAN ATAMA 
	cout << "Dizinin Ilk Hali :";
	for (int i = 0; i < boyut; i++) {
		dizi[i] = rand() % 200;
		cout << dizi[i] << "  ";
	}
	cout << "\n";
	cout << "\n";
	int degistir;
	int mesafe = boyut / sabit;
	//AŞAGIDA  GEREKLİ İŞLEMLER YAPILDI VE DİZİ SİRALANMIS OLDU.5

	while (mesafe>0) {
		for (int i = 0; i < boyut; i++) {
			if (i + mesafe < boyut) {
				if (dizi[i]>dizi[i + mesafe]) {
					cout << "MESAFE :" << mesafe << "-----" << dizi[i] << ">" << dizi[i + mesafe] << " Oldugu icin yer degisti\n";
					degistir = dizi[i];
					dizi[i] = dizi[i + mesafe];
					dizi[i + mesafe] = degistir;
				}
				else {
					cout << "MESAFE :" << mesafe << "-----" << dizi[i] << "<" << dizi[i + mesafe] << " oldugu icin degisim olmaz\n";}
			}
		}
		mesafe = mesafe / sabit;	}
	//SIRALANMIŞ DİZİYİ EKRANA YAZDIRMA
	cout << "\n";
	cout << "Dizinin siralanmis hali  :";
	for (int i = 0; i < boyut; i++) {
		cout << dizi[i] << "  ";
	}
	cout << "\n";
	time_req = clock() - time_req;
	cout << "Algoritmanin Calisma Suresi " << (float)time_req/CLOCKS_PER_SEC << " saniyedir." << endl;
	system("pause");
	}
	else if (secim==2)
	{
		clock_t time_req;
	time_req = clock();
	int a[] = {8,15,78,4,4,5,5,6,9,10,56,78,560,780,98,789};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	cout<<"Dizinin Elemanlari:"<<endl;
	yazdir(a,sz);
	cout << "----------------------\n" ;
	cout<<"Dizinin Siralanmis Hali:"<<endl;
	SaymaSiralamasi(a, sz);
	time_req = clock() - time_req;

	cout << "Fonksiyonun Calisma Suresi" <<endl<< (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	system("pause");
	}
	else if (secim==3)
	{
		clock_t time_req;
	time_req = clock();
	
	

	int dizi[] = {5,1,4,2,8,0,2,89,78,65,5,25,30,14,789,547}; 
	cout<<"Dizinin ilk hali:";
	for(int i=0; i<16;i++)
	{  
		cout<<dizi[i]<<" ";
		
	}
	cout<<endl;
	int n = sizeof(dizi) / sizeof(dizi[0]); 
	CocktailSort(dizi, n); 
	cout<<"Dizinin Siralanmis Hali"<<endl; 
	 diziyiyazdir(dizi, n); 
	time_req = clock() - time_req;
	
	cout << "Algoritmanin Calisma Suresi " << (float)time_req/CLOCKS_PER_SEC << " saniyedir." << endl;
	system ("pause");
	}
	else if (secim==4)
	{
		int boyut;
	int *dizi;
	cout << "SABIT  SAYI   :" << sabit << "\n";
	cout << "Dizinin Boyutunu Giriniz:";
	cin >> boyut;
	cout << "\n";
	srand(time(NULL));
	dizi = new int[boyut]; 
	clock_t time_req;
	time_req = clock();
	//POİNTER DİZİ OLUSTURMA 
	 //POİNTER DİZİYE RASTGELE ELEMAN ATAMA 
	cout << "Dizinin Ilk Hali :";
	for (int i = 0; i < boyut; i++) {
		dizi[i] = rand() % 200;
		cout << dizi[i] << "  ";
	}
	cout << "\n";
	cout << "\n";
	int degistir;
	int mesafe = boyut / sabit;
	//AŞAGIDA  GEREKLİ İŞLEMLER YAPILDI VE DİZİ SİRALANMIS OLDU.5

	while (mesafe>0) {
		for (int i = 0; i < boyut; i++) {
			if (i + mesafe < boyut) {
				if (dizi[i]>dizi[i + mesafe]) {
					cout << "MESAFE :" << mesafe << "-----" << dizi[i] << ">" << dizi[i + mesafe] << " Oldugu icin yer degisti\n";
					degistir = dizi[i];
					dizi[i] = dizi[i + mesafe];
					dizi[i + mesafe] = degistir;
				}
				else {
					cout << "MESAFE :" << mesafe << "-----" << dizi[i] << "<" << dizi[i + mesafe] << " oldugu icin degisim olmaz\n";}
			}
		}
		mesafe = mesafe / sabit;	
	}
	cout << "\n";
	
		cout << "Dizinin siralanmis hali  :"<<endl;
	for (int i = 0; i < boyut; i++) {
		cout << dizi[i] << "  ";
	}
	cout<<endl;
	time_req = clock() - time_req;
	cout << "Comb Algoritmanin Calisma Suresi " << (float)time_req/CLOCKS_PER_SEC << " saniyedir." << endl;
	cout<<endl;

	time_req = clock();
	int a[] = {8,15,78,4,4,5,5,6,9,10,56,78,560,780,98,789,45,586,654,21,3012,4789,5478,23,545,54,65,41,25,14};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	yazdir(a,sz);
	time_req = clock() - time_req;

	cout << "counting Fonksiyonun Calisma Suresi" <<endl<< (float)time_req/CLOCKS_PER_SEC << " saniyedir" << endl;


	time_req = clock();
	
	

	int dizik[] = {5,1,4,2,8,0,2,89,78,65,5,25,30,14,789,547,86,87,899,874,5632,789547,895,012,3214,248,3654,784,74,56};
	cout<<endl;
	int n = sizeof(dizik) / sizeof(dizik[0]); 
	CocktailSort(dizik, n); 
	time_req = clock() - time_req;
		diziyiyazdir(dizik,n);
	cout << "kokteyl Algoritmanin Calisma Suresi " << (float)time_req/CLOCKS_PER_SEC << " saniyedir." << endl;
	
	time_req = clock();
	system ("pause");

	}



	return 0;}


