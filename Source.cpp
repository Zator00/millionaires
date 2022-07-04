#include <iostream>
#include <cstdlib>
#include <time.h>
#include "pytanie.h"
/*
* ilosc pytan w pliku tekstowym ;
*  wystarczy zmienic liczbe pytan w tym miejscu i program dostosowuje siê pod dan¹ liczbê pytañ;
* liczba to nie mo¿e byæ mneijsza ni¿ 12
*/
#define ilosc_pytan 20 

using namespace std;
void instrukcja()		//funkcja wyœwietlaj¹ca intrukcjê gry
{
	cout << endl;
	cout << "W grze milionerzy starasz sie poprawnie odpowiedziec na zadawane ci pytania." << endl;
	cout << "Kazda poprawna odpowiedz dodaje kwote do twojej wygranej. (Kwaota nad pytaniem)" << endl;
	cout << "Odpowiadasz za pomoca wcisniecia odpowiednego klawisza (a,b,c lub d)" << endl;
	cout << "Upewnij sie, ze nie masz wlaczonego CAPSLOCKa" << endl;
	cout << "Gwarantowane kwoty to 1000 (2.pytanie) oraz 40000 (7. pytanie)" << endl;
	cout << "Przy udzielaniu odpowiedzi na pytanie, w kazdej chwili mozna wcisnac 'k', aby zabrac kwote gwarantowana." << endl;
	cout << "Wcisnij g aby zaczac gre: ";
};
void menu()  //funkcja wyœwietlaj¹ca menu gry
{
	cout << "Witaj w grze pod tytulem 'MILIONERZY'!" << endl;
	cout << "Jezei grasz po raz pierwszy PRZECZYTAJ instukcje !!!" << endl;
	cout << "Jesli chcesz otworzyc instrukcje gry wcisnij 'i'," << endl;
	cout << "jesli chcesz przejsc do gry wcisnij 'g'." << endl;
	char wyb = 'a';
	do 
	{
		cout << "Wybor: ";
		cin >> wyb;
		switch (wyb)
		{
		case 'i':
		{
			instrukcja();
			break;
		}
		case 'g':
		{
			cout << endl << "Zaczynamy!!!" << endl;
			break;
		}
		default:
		{
			cout << "Nie ma takiej opji. Sprobuj ponownie." << endl;
		}
		};
	} while (wyb != 'g');
};
bool powtorka(int iLiczba, int tablica[], int ile) //funkcja sprawdzaj¹ca czy liczba by³a ju¿ wylosowana
{
	if (ile <= 0)
		return false;

	int i = 0;
	do
	{
		if (tablica[i] == iLiczba)
			return true;

		i++;
	} while (i < ile);

	return false;
}
int wylosuj() // funkcja losuj¹ca liczbê z przedzia³u od 1 do liczby pytañ w pliku tekstowym
{
	return(rand() % ilosc_pytan) + 1;
}

int main()
{
	menu();
	int money = 0;	//wygrane pieni¹dze 
	int gwarantowana = 0; // gwaarantowana kwota przy nieprawid³owej odpowiedzi
	int los; //liczba losowa
	srand(time(NULL));
	cout << endl;
	for (int i = 0; i < 120; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << "!!! Jesli chcesz zrezygnowac z dalszej gry w dowolnym momencie i zakonczyc gre w poprzzednia kwota wcisnij 'k'!!!" << endl;
	Pytanie p[ilosc_pytan]; //stworzenie tablicy obiektów z klasy Pytanie
	for (int i = 0; i <= ilosc_pytan - 1; i++) // petla wczytujaca wszystkie pytania do tablicy obiektow
	{
		p[i].nr_pytania = i + 1;
		p[i].wczytaj();
	}
	srand(time(0));
	int wylosowane[12];
	int wylosowanych = 0;   
	// losowanie liczby
	do
	{
		int los = wylosuj();
		if (powtorka(los, wylosowane, wylosowanych) == false)
		{
			wylosowane[wylosowanych] = los;
			wylosowanych++;
		} //if
	} while (wylosowanych < 12);
	for (int i = 0; i <= 11; i++)
	{
		for (int j = 0; j < 120; j++) // pêtla rysuj¹ca linie z kresek (zabieg stylistyczny)
		{
			cout << "-";
		}
		cout << endl;
		switch (i)				//switch pokazuj¹cy wartoœæ pytania
		{
		case 0:
		{
			cout << endl << "To pytanie jest warte 500 zl." << endl;
			break;
		}
		case 1:
		{
			cout << endl << "To pytanie jest warte 1000 zl." << endl;
			break;
		}
		case 2:
		{
			cout << endl << "To pytanie jest warte 2000 zl." << endl;
			break;
		}
		case 3:
		{
			cout << endl << "To pytanie jest warte 5000 zl." << endl;
			break;
		}
		case 4:
		{
			cout << endl << "To pytanie jest warte 10000 zl." << endl;
			break;
		}
		case 5:
		{
			cout << endl << "To pytanie jest warte 20000 zl." << endl;
			break;
		}
		case 6:
		{
			cout << endl << "To pytanie jest warte 40000 zl." << endl;
			break;
		}
		case 7:
		{
			cout << endl << "To pytanie jest warte 75000 zl." << endl;
			break;
		}
		case 8:
		{
			cout << endl << "To pytanie jest warte 125000 zl." << endl;
			break;
		}
		case 9:
		{
			cout << endl << "To pytanie jest warte 250000 zl." << endl;
			break;
		}
		case 10:
		{
			cout << endl << "To pytanie jest warte 500000 zl." << endl;
			break;
		}
		case 11:
		{
			cout << endl << "To pytanie jest warte 1000000 zl." << endl;
			break;
		}
		default:
		{
			cout << "Wystapil blad w dzialaniu programu." << endl;
			exit(1);
		}
		};
		cout << endl;
		cout << i + 1 << ".";
		p[wylosowane[i]].zadaj();  // wyœwietlenie pytania na ekranie
		p[wylosowane[i]].sprawdz(); // sprawdzenie poprawnej odpowiedzi
		if (p[wylosowane[i]].punkt == 1)  // if sprawdzaj¹cy wygran¹ \ przegran¹
		{
			switch (i)		//switch przypisuj¹cy wartoœæ pytania do wygranej
			{
			case 0:
			{
				money = 500;
				break;
			}
			case 1:
			{
				money = 1000;
				gwarantowana = 1000;
				break;
			}
			case 2:
			{
				money = 2000;
				break;
			}
			case 3:
			{
				money = 5000;
				break;
			}
			case 4:
			{
				money = 10000;
				break;
			}
			case 5:
			{
				money = 20000;
				break;
			}
			case 6:
			{
				money = 40000;
				gwarantowana = 40000;
				break;
			}
			case 7:
			{
				money = 75000;
				break;
			}
			case 8:
			{
				money = 125000;
				break;
			}
			case 9:
			{
				money = 250000;
				break;
			}
			case 10:
			{
				money = 500000;
				break;
			}
			case 11:
			{
				money = 1000000;
				gwarantowana = 1000000;
				break;
			}
			default:
			{
				cout << "Wystapil blad w dzialaniu programu." << endl;
				exit(1);
			}
			};
		}
		else if (p[wylosowane[i]].punkt == 0 || money==100000)
			{
			cout << "KONIEC GRY. TWOJA WYGRANA: " << gwarantowana << " zl."<<endl;
			p[wylosowane[i]].odp_pop(); //wyœwietlenie poprawnej odpowiedzi na ekranie
			exit(0);
			}
		else if (p[wylosowane[i]].punkt == 2 || money == 100000)
		{
			cout << "KONIEC GRY. TWOJA WYGRANA: " << money << " zl." << endl;
			p[wylosowane[i]].odp_pop(); //wyœwietlenie poprawnej odpowiedzi na ekranie
			exit(0);
		}
		if (money == 1000000) // warunek wygrania ca³ej gry
		{
			cout << "GRATULACJE!!! WLASNIE WYGRALES 1000000 ZL!!!" << endl;
		}
	};
	return 0;
}
