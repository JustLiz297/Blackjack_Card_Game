#pragma once

#pragma once

#include <string>
#include <iostream> // For cin, cout, etc.
#include <cmath>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;


struct Card {
	int rank;
	string suit;
};


//string ConvertIntToSuit(int suitNum);
//Card RandomCard();
Card DealerDealt(string array[], int& currentCardIndex, const int DECK_SIZE = 52);
void CardTotal(Card& card, int& currentTotal);
Card PlayerDealt(string array[], int& currentCardIndex, const int DECK_SIZE = 52);
void PrintScore(int currentTotal, string user);
void ShuffleDeck(string array[], const int DECK_SIZE = 52);
Card GetNextCard(string array[], int& currentCardIndex, const int DECK_SIZE = 52);