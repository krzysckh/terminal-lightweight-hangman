COMPILER = g++
OUT_NAME = hangman

hangman:
	$(COMPILER) hangman.cpp -o $(OUT_NAME)
