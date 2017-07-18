#include <iostream> // For cin, cout, etc.
#include <cmath>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Card {
	int rank;
	string suit;
};


/*string ConvertIntToSuit(int suitNum) {
	switch (suitNum) {
	case 0:
		return "Hearts";
	case 1:
		return "Clubs";
	case 2:
		return "Diamonds";
	case 3:
	default:
		return "Spades";
	}
}
*/
Card GetNextCard (string array[], int& currentCardIndex, const int DECK_SIZE = 52) {
	Card card;
	string drawnCard = array[currentCardIndex];
	if (drawnCard.at(0) == 'A') {
		card.rank = 1;
	}
	else if (drawnCard.at(0) == '2') {
		card.rank = 2;
	}
	else if (drawnCard.at(0) == '3') {
		card.rank = 3;
	}
	else if (drawnCard.at(0) == '4') {
		card.rank = 4;
	}
	else if (drawnCard.at(0) == '5') {
		card.rank = 5;
	}
	else if (drawnCard.at(0) == '6') {
		card.rank = 6;
	}
	else if (drawnCard.at(0) == '7') {
		card.rank = 7;
	}
	else if (drawnCard.at(0) == '8') {
		card.rank = 8;
	}
	else if (drawnCard.at(0) == '9') {
		card.rank = 9;
	}
	else if (drawnCard.at(0) == '1') {
		card.rank = 10;
	}
	else if (drawnCard.at(0) == 'J') {
		card.rank = 11;
	}
	else if (drawnCard.at(0) == 'Q') {
		card.rank = 12;
	}
	else if (drawnCard.at(0) == 'K') {
		card.rank = 13;
	}
	else {
		cout << "error" << endl;
	}
	if (drawnCard.find("Hearts") != (string::npos)) {
		card.suit = "Hearts";
	}
	else if (drawnCard.find("Diamonds") != (string::npos)) {
		card.suit = "Diamonds";
	}
	else if (drawnCard.find("Spades") != (string::npos)) {
		card.suit = "Spades";
	}
	else {
		card.suit = "Clubs";
	}
	currentCardIndex++;
	return card;
}

/*Card RandomCard() {
	Card card;
	card.rank = ((rand() % 13) + 1);
	card.suit = ConvertIntToSuit((rand() % 4));

	return card;
}
*/
Card DealerDealt(string array[], int& currentCardIndex, const int DECK_SIZE = 52) {
	Card card;
	string cardTitle;
	card = GetNextCard(array, currentCardIndex, DECK_SIZE);
	if (card.rank == 1) {
		cout << "Dealer shows the " << "Ace " << "of " << card.suit << endl;
	}
	else if (card.rank == 11) {
		cout << "Dealer shows the " << "Jack" << " of " << card.suit << endl;
	}
	else if (card.rank == 12) {
		cout << "Dealer shows the " << "Queen" << " of " << card.suit << endl;
	}
	else if (card.rank == 13) {
		cout << "Dealer shows the " << "King" << " of " << card.suit << endl;
	}
	else {
		cout << "Dealer shows the " << card.rank << " of " << card.suit << endl;
	}
	return card;
}

void CardTotal(Card& card, int& currentTotal) {
	currentTotal += card.rank;

	return;
}
Card PlayerDealt(string array[], int& currentCardIndex, const int DECK_SIZE = 52) {
	Card card;
	card.rank = 0;
	card = GetNextCard(array, currentCardIndex, DECK_SIZE);
	if (card.rank == 1) {
		cout << "You were dealt the " << "Ace " << "of " << card.suit << endl;
	}
	else if (card.rank == 11) {
		cout << "You were dealt the " << "Jack" << " of " << card.suit << endl;
	}
	else if (card.rank == 12) {
		cout << "You were dealt the " << "Queen" << " of " << card.suit << endl;
	}
	else if (card.rank == 13) {
		cout << "You were dealt the " << "King" << " of " << card.suit << endl;
	}
	else {
		cout << "You were dealt the " << card.rank << " of " << card.suit << endl;
	}
	return card;
}
void PrintScore(int currentTotal, string user) {
	cout << user << " total is: " << currentTotal << endl;

	return;

}

void ShuffleDeck(string array[], const int DECK_SIZE = 52) {
	string numHolder;
	for (int i = 0; i < DECK_SIZE; i++) {
		int pos1 = (rand() % 52);
		int pos2 = (rand() % 52);
		numHolder = array[pos1];
		array[pos1] = array[pos2];
		array[pos2] = numHolder;
	}

	return;
}