#include <iostream>

using namespace std;

class Tresc // klasa przechowuj�ca tre�� pytania
{
protected:			// dane pytania s� prywatne poza klas� pochodn�
	string tresc;   // tre�� pytania
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
	void zadaj();	// wy�wietlaj pytanie wraz z odpowiedziami
	void sprawdz();	// sprawdza poprawna odpowiedz
	void odp_pop(); // po b��dnej odpowiedzi pokazuje prawid�ow� odpowied�
};