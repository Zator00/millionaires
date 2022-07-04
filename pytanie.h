#include <iostream>

using namespace std;

class Tresc // klasa przechowuj¹ca treœæ pytania
{
protected:			// dane pytania s¹ prywatne poza klas¹ pochodn¹
	string tresc;   // treœæ pytania
	string a, b, c, d;  //odpowiedzi
	string poprawna;	//informacja o poprawnej odpowiedzi
	string odp;			// odpowiedz gracza
};

class Pytanie: public Tresc  //klasa pochodna Pytanie 
{
public:
	int nr_pytania;
	int punkt;
	void wczytaj(); // wczytaj pytanie z pliku
	void zadaj();	// wyœwietlaj pytanie wraz z odpowiedziami
	void sprawdz();	// sprawdza poprawna odpowiedz
	void odp_pop(); // po b³êdnej odpowiedzi pokazuje prawid³ow¹ odpowiedŸ
};