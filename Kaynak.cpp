#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;

class Ogrenci
{
private:
	string isim;
	string soyisim;
	int numara;
public:                                // get set metotlar private degiskenleri degistrmemize yarýyor

	void setIsim(string isim)
	{
		this->isim = isim;
	}
	void setSoyisim(string soyisim)
	{
		this->soyisim = soyisim;
	}
	void setNumara(int No)
	{
		this->numara = No;
	}

	string getIsim()
	{
		return isim;
	}
	string getSoyisim()
	{
		return soyisim;
	}

	int getNumara()
	{
		return numara;
	}

};

class Sinif

{

public:

	string sinifIsmi;
	int ogrenciSayisi;
	Ogrenci ogrenciler[100];

	char isimOlustur() {
		const char dizi2[] = "ABCDEFGHIJKLMNOPRSTUVYZQX";
		char sube2 = dizi2[rand() % 25];
		return sube2;
	}
	void addOgrenci(Ogrenci ogr)
	{

		ogrenciler[ogrenciSayisi] = ogr;
		ogrenciSayisi++;
	}
	void deleteOgrenci(int no)
	{
		for (int i = 0; i < ogrenciSayisi; i++)       //Butun ogrencileri dolasir
		{
			if (ogrenciler[i].getNumara() == no)        //Parametre gelen ogrenci no ile eslesir
			{
				for (int j = i; j < ogrenciSayisi; j++) //Bir sonraki ogrenciyi bir onceye alarak secilen ogrenci en sona getirilir
					ogrenciler[j] = ogrenciler[j + 1];


				ogrenciSayisi--;
				break;
			}

		}
	}
	void OgrenciDegistir(int no, Ogrenci o)
	{
		for (int i = 0; i < ogrenciSayisi; i++)
		{
			if (ogrenciler[i].getNumara() == no)             //Ogrenci eslesir ve degisir
			{
				ogrenciler[i] = o;
				break;
			}
		}
	}
};

class Okul
{
public:
	int sinifSayisi;
	Sinif siniflar[10];
	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;

	void ustYazdir(int elemanSayisi)
	{
		cout << solUstKose;
		for (int i = 0; i < elemanSayisi; i++)
			cout << duz;

		cout << sagUstKose;
	}

	void altYazdir(int elemanSayisi)
	{
		cout << solAltKose;
		for (int i = 0; i < elemanSayisi; i++)
			cout << duz;
		cout << sagAltKose;
	}



	void Sinifyazdir(int elemanSayisi)
	{
		int max = 0;
		for (int i = 0; i < sinifSayisi; i++)

			if (siniflar[i].ogrenciSayisi > max)

				max = siniflar[i].ogrenciSayisi;

		for (int j = 0; j < max; j++)
		{
			for (int x = 0; x < sinifSayisi; x++)

				if (siniflar[x].ogrenciSayisi > j)

					ustYazdir(elemanSayisi);
				else
					cout << setw(elemanSayisi + 2) << " ";

			cout << endl;

			for (int y = 0; y < sinifSayisi; y++)

				if (siniflar[y].ogrenciSayisi > j)

					cout << dikey << setw(elemanSayisi) << siniflar[y].ogrenciler[j].getIsim() << dikey;
				else
					cout << setw(elemanSayisi + 2) << " ";

			cout << endl;
			for (int y = 0, t = 0; y < sinifSayisi; y++)

				if (siniflar[y].ogrenciSayisi > j)

					cout << dikey << setw(elemanSayisi) << siniflar[y].ogrenciler[j].getSoyisim() << dikey;
				else
					cout << setw(elemanSayisi + 2) << " ";

			cout << endl;
			for (int y = 0, t = 0; y < sinifSayisi; y++)

				if (siniflar[y].ogrenciSayisi > j)

					cout << dikey << setw(elemanSayisi) << siniflar[y].ogrenciler[j].getNumara() << dikey;
				else
					cout << setw(elemanSayisi + 2) << " ";

			cout << endl;
			for (int x = 0; x < sinifSayisi; x++)

				if (siniflar[x].ogrenciSayisi > j)

					altYazdir(elemanSayisi);
				else
					cout << setw(elemanSayisi + 2) << " ";
			cout << endl;
		}

	}
	void SubeYazdir(int elemanSayisi, int sayi)
	{
		for (int i = 0; i < sayi; i++)
			ustYazdir(elemanSayisi);

		cout << endl;
		for (int i = 0; i < sayi; i++)
			cout << dikey << setw((elemanSayisi / 2) + 1) << siniflar[i].sinifIsmi << setw((elemanSayisi / 2)) << dikey;

		cout << endl;
		for (int i = 0; i < sayi; i++)
			altYazdir(elemanSayisi);
	}
	void Sinifekle(Sinif s)
	{
		siniflar[sinifSayisi] = s;
		sinifSayisi++;
	}
	void SinifSil(string sinifIsmi)
	{
		for (int i = 0; i < sinifSayisi; i++) //Ogrenci sil ile birebir
		{
			if (siniflar[i].sinifIsmi == sinifIsmi)
			{

				for (int x = 0; x < siniflar[i].ogrenciSayisi; x++)
					siniflar[i].deleteOgrenci(siniflar[i].ogrenciler[x].getNumara());
				for (int j = i; j < sinifSayisi; j++)
					siniflar[j] = siniflar[j + 1];
				sinifSayisi--;
				break;
			}
		}
	}
};

class DosyaYonetimi
{
public:

	Okul okulOku(string dosyaIsmi)
	{
		Okul okul;

		fstream dosya(dosyaIsmi);

		int sinifSayisi = 0;

		while (dosya.eof() != true)
		{
			string sinifIsmi;
			int ogrenciSayisi;
			dosya >> sinifIsmi >> ogrenciSayisi;

			okul.siniflar[sinifSayisi].sinifIsmi = sinifIsmi;
			okul.siniflar[sinifSayisi].ogrenciSayisi = ogrenciSayisi;

			for (int i = 0; i < ogrenciSayisi; i++)
			{
				string ad, soyad;
				int numara;
				dosya >> ad >> soyad >> numara;
				okul.siniflar[sinifSayisi].ogrenciler[i].setIsim(ad);
				okul.siniflar[sinifSayisi].ogrenciler[i].setSoyisim(soyad);
				okul.siniflar[sinifSayisi].ogrenciler[i].setNumara(numara);
			}

			sinifSayisi++;
		}
		okul.sinifSayisi = sinifSayisi;
		dosya.close();
		return okul;

	}

	void okulYazdir(Okul okul)
	{
		fstream dosya("kayitlar.txt", ios::out);

		for (int i = 0; i < okul.sinifSayisi; i++)
		{
			dosya << okul.siniflar[i].sinifIsmi << endl;
			dosya << okul.siniflar[i].ogrenciSayisi << endl;

			for (int j = 0; j < okul.siniflar[i].ogrenciSayisi; j++)
			{
				dosya << okul.siniflar[i].ogrenciler[j].getIsim() << " ";
				dosya << okul.siniflar[i].ogrenciler[j].getSoyisim() << " ";
				dosya << okul.siniflar[i].ogrenciler[j].getNumara();
			}
		}

	}
	Ogrenci ogrenciGetir()
	{
		isimOku();
		SoyisimOku();
		Ogrenci ogrenci;

		ogrenci.setIsim(isimler[rand() % 100]);
		ogrenci.setSoyisim(soyisimler[rand() % 100]);
		ogrenci.setNumara(rand() % 100 + 100);

		return ogrenci;
	}
	void isimOku()
	{
		fstream isimlerD("isimler.txt");
		string temp;
		int i = 0;

		if (isimlerD.is_open())

			while (isimlerD >> temp && i != 100)
			{
				isimler[i] = temp;
				i++;
			}
		isimlerD.close();
	}
	void SoyisimOku()
	{
		fstream soyisimD("soyisimler.txt");
		string temp;

		int i = 0;

		if (soyisimD.is_open())

			while (soyisimD >> temp && i != 100)
			{
				soyisimler[i] = temp;
				i++;
			}
		soyisimD.close();
	}
	Ogrenci getOgrenci() //Rastgele ogrenci getiren fonksiyon
	{
		isimOku();
		SoyisimOku();
		Ogrenci ogr;
		srand(time(0));
		ogr.setIsim(isimler[rand() % 100]);
		ogr.setSoyisim(soyisimler[rand() % 100]);
		ogr.setNumara(rand() % 100 + 100);

		return ogr;
	}
	string isimler[100];
	string soyisimler[100];
};

class Program
{

public:
	DosyaYonetimi dy;

	Okul okul;

	void Calistir()
	{
		const int elemansayisi = 18;

		bool kontrol = true;

		okul = dy.okulOku("kayitlar.txt");

		while (kontrol)
		{
			okul.SubeYazdir(elemansayisi, okul.sinifSayisi);
			cout << endl;
			okul.Sinifyazdir(elemansayisi);
			cout << "1.Ogrenci ekle...:" << endl
				<< "2.Sinif ekle...:" << endl
				<< "3.Ogrenci degistir...:" << endl
				<< "4.Ogrenci sil...:" << endl
				<< "5.Sinif sil...:" << endl
				<< "6.Cikis...:" << endl;
			int secim = 0;
			cout << "Yapmak istediginiz islemi seciniz...:";
			Ogrenci ogr;
			Sinif snf;
			string sa;
			string sinifIsmi;
			cin >> secim;

			switch (secim)
			{
			case 1:
				ogr = dy.ogrenciGetir();
				cout << "Sinif adi giriniz : "; cin >> sa;
				for (int i = 0; i < okul.sinifSayisi; i++)
				{
					if (okul.siniflar[i].sinifIsmi == sa)
					{
						okul.siniflar[i].addOgrenci(ogr);
						break;
					}

				}
				break;
			case 2:

				snf.sinifIsmi = to_string(okul.sinifSayisi + 1) + snf.isimOlustur();
				okul.Sinifekle(snf);

				break;
			case 3:

				int numara;
				ogr = dy.getOgrenci();
				cout << "Numara girin : ";
				cin >> numara;
				for (int i = 0; i < okul.sinifSayisi; i++)
					okul.siniflar[i].OgrenciDegistir(numara, ogr);
				break;

			case 4:

				int no;
				cout << "Numara giriniz.. : ";
				cin >> no;

				for (int i = 0; i < okul.sinifSayisi; i++)
				{
					okul.siniflar[i].deleteOgrenci(no);
				}
				break;

			case 5:
				cout << "sinif adi girin : ";
				cin >> sinifIsmi;
				for (int i = 0; i < okul.sinifSayisi; i++)
					if (okul.siniflar[i].sinifIsmi == sinifIsmi)
					{
						okul.SinifSil(sinifIsmi);
						break;
					}
				break;

			case 6:

				kontrol = false;
				break;
			}
		}

	}

};

int main()
{
	Program prog;
	prog.Calistir();


	cin.get();
	return 0;
}

