#include <iostream>
#include <string>
#include <ctime>
#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif
using namespace std;
//set amount of words here
const int ILOSCSLOW = 30;

void clrScr(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
int main()
{
	clrScr();
	srand(time(NULL));
	cout << "welcome to hangman\n";
	cout << "you'll have 10 attempts to guess a word!\n";
	cout << "you can guess a word, but you can also guess single letters\n\n";
	//WRITE WORDS IN THIS STRING ARRAY!!
	string slowo[ILOSCSLOW] {"amer","anegdote","germany","jazz","keyboard","word","letter","york","linux","pope","graph", "woman",
		"guitar","ted","film","gaming","generetor","meme","cat","water","undefined21","undefined22","undefined23","undefined24","undefined25",
		"undefined26","undefined28","undefined29","undefined30"};
	string slowoDoOdgadniecia = slowo[rand()%ILOSCSLOW];
	int dlugoscSlowa = slowoDoOdgadniecia.length();
	string slowoLiterami[dlugoscSlowa];
	string pokazSlowo [dlugoscSlowa];
	for (int i = 0; i < dlugoscSlowa; i++){
		pokazSlowo[i] = "_ ";
	}
	for (int i = 0; i<dlugoscSlowa; i++){
		slowoLiterami[i] = slowoDoOdgadniecia.substr(i,1);
		/*cout << slowoLiterami[i] << endl;*/
	}
	//YOU CAN SHANGE NUMBER OF GUESSES IN THIS INITGERRRRRR
	int iloscProb = 10;
	bool czyPodanyZnak, czyWygrana, czyPrzegrana, czyKoniec;
	czyKoniec = 0;
	czyPrzegrana = 0;
	czyWygrana = 0;
	int aaa = 0;
	while (czyKoniec == 0){
		cout << endl;
		for (int i = 0; i<dlugoscSlowa; i++){
			cout << pokazSlowo[i];
		}
		cout << endl;
		cout << "enter a letter or a word" << endl;
		string podanyZnak, podaneSlowo, podanyCiag;
		cin >> podanyCiag;
		if (podanyCiag.length() > 1){
			podaneSlowo = podanyCiag;
			czyPodanyZnak = 0;
		} else {
			podanyZnak = podanyCiag;
			czyPodanyZnak = 1;
		}
		if (czyPodanyZnak == 0){
			if (podaneSlowo == slowoDoOdgadniecia){
				/*cout << endl << endl << "gratulacje!! twoje slowo to " << slowoDoOdgadniecia << " i udalo ci sie je odgadnąć\n";*/
				czyWygrana = 1;
				czyKoniec = 1;
			} else {
				iloscProb--;
				cout << endl << "wrong mateee\n" << endl;
			}

		} else {
			int aa = 0;
			for (int i = 0; i<dlugoscSlowa; i++){
				if (podanyCiag == slowoLiterami[i]){
					pokazSlowo[i] = slowoLiterami[i] + " ";
					aa++;
					aaa++;
				}
			}
			if (aa == 0){
				cout << "\n nope\n";
				iloscProb--;
			} else {
				iloscProb--;
			}
		if (aaa == dlugoscSlowa){
			czyKoniec = 1;
			czyWygrana = 1;
		}
		if (iloscProb < 1){
			czyKoniec = 1;
			czyPrzegrana = 1;
		}
	
	}
	cout << "\nyou have " << iloscProb << " attempts left\n\n";
	}
	if (czyPrzegrana == 1){
		cout << "you lost.\nyour word was " << slowoDoOdgadniecia << endl;
	} else if (czyWygrana == 1){
		cout << endl << endl << "congrats! your word was " << slowoDoOdgadniecia << " and you guessed it right!" << endl;
		return 0;
	}
}
