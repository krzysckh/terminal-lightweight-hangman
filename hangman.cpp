#include "hangman.h"

using namespace std;

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
	string slowoDoOdgadniecia = slowo[rand()%ILOSCSLOW];
	int dlugoscSlowa = slowoDoOdgadniecia.length();
	string slowoLiterami[dlugoscSlowa];
	string pokazSlowo [dlugoscSlowa];
	for (int i = 0; i < dlugoscSlowa; i++){
		pokazSlowo[i] = "_ ";
	}
	for (int i = 0; i<dlugoscSlowa; i++){
		slowoLiterami[i] = slowoDoOdgadniecia.substr(i,1);
	}
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
				czyWygrana = 1;
				czyKoniec = 1;
			} else {
				iloscProb--;
				cout << endl << "wrong wrong guess\n" << endl;
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
				cout << "\nnope\n";
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
