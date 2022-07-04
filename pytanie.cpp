#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

void Pytanie::wczytaj()  //metoda wczytuj¹ca pytania z pliku .txt zanjduj¹cego sie w katalogu z programem
{
	fstream plik;
	plik.open("Pytania_odp.txt", ios::in);

	if (plik.good() == false)  // sprwdzenie czy plik siê poprawnie otworzy³
	{
		cout << "Nie udalo sie otworzyc pliku!" << endl;
	}

	int nr_linii = (nr_pytania - 1) * 6 + 1;
	int aktualny_nr = 1;
	string linia;

	while (getline(plik, linia))    // pêtla wczytuj¹ca z pliku .txt
	{
		if (aktualny_nr == nr_linii)
			tresc = linia;
		if (aktualny_nr == nr_linii + 1)
			a = linia;
		if (aktualny_nr == nr_linii + 2)
			b = linia;
		if (aktualny_nr == nr_linii + 3)
			c = linia;
		if (aktualny_nr == nr_linii + 4)
			d = linia;
		if (aktualny_nr == nr_linii + 5)
			poprawna = linia;
		aktualny_nr++;
	}
	plik.close();
};

void Pytanie::zadaj()  // metoda zadaj¹ca pytanie
{
	cout << tresc <<endl;
	cout << "a. " << a << endl;
	cout << "b. " << b << endl;
	cout << "c. " << c << endl;
	cout << "d. " << d << endl;
	cout << endl;
	cout << "Twoja odpowiedz: ";
	cin >> odp;
	
};

void Pytanie::sprawdz()  // metoda sprwdzaj¹ca poprawn¹ odpowiedŸ
{
	if (odp == poprawna) //(warunek)przyznanie punku za poprawn¹ odpowiedz
	{
		punkt = 1;
	}
	else if (odp == "k")  // (warunek)  wpisanie literki 'k' powoduje zakonczenie gry z wygran¹ z poprzedniego pytania
		punkt = 2;
	else
		punkt = 0;  // (warunek)
};

void Pytanie::odp_pop() // metoda pokazuj¹ca poprawn¹ odpowiedz na ekranie 
{
	cout << "Porawna odpowiedz to: "<< poprawna << endl;
}
