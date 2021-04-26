#include <iostream>
#include <ctime>

#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif

//you can set the number of words here
//tutaj zmień ilość słów

const int ILOSCSLOW = 30;

//you can set the words in this string array. remember to compile the file once again afterwards
//tu można zmienić używane słowa. pamiętaj o skompilowaniu programu jeszcze raz po zmianie

std::string slowo[ILOSCSLOW] {"amer","anegdote","germany","jazz","keyboard","word","letter","york","linux","pope","graph", "woman",
	"guitar","ted","film","gaming","generetor","meme","cat","water","undefined21","undefined22","undefined23","undefined24","undefined25",
	"undefined26","undefined28","undefined29","undefined30"};


//you can set number of guesses here
//tu zmień ilość prób

int iloscProb = 10;
