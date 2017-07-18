/* CSCI 261 Lab A07: Smart Blackjack
*
* Author: Elizabeth (Liz) Boyle
*
* Using an array to track our deck of cards to make our blackjack game "smart"
*/



#include "functions.h"


using namespace std;

int main() {
	const int DECK_SIZE = 52;
	string cardStack[DECK_SIZE];
	cardStack[0] = "Ace of Hearts";
	cardStack[1] = "2 of Hearts";
	cardStack[2] = "3 of Hearts";
	cardStack[3] = "4 of Hearts";
	cardStack[4] = "5 of Hearts";
	cardStack[5] = "6 of Hearts";
	cardStack[6] = "7 of Hearts";
	cardStack[7] = "8 of Hearts";
	cardStack[8] = "9 of Hearts";
	cardStack[9] = "10 of Hearts";
	cardStack[10] = "Jack of Hearts";
	cardStack[11] = "Queen of Hearts";
	cardStack[12] = "King of Hearts";
	cardStack[13]= "Ace of Spades";
	cardStack[14] = "2 of Spades";
	cardStack[15] = "3 of Spades";
	cardStack[16] = "4 of Spades";
	cardStack[17] = "5 of Spades";
	cardStack[18] = "6 of Spades";
	cardStack[19] = "7 of Spades";
	cardStack[20] = "8 of Spades";
	cardStack[21] = "9 of Spades";
	cardStack[22] = "10 of Spades";
	cardStack[23] = "Jack of Spades";
	cardStack[24] = "Queen of Spades";
	cardStack[25] = "King of Spades";
	cardStack[26] = "Ace of Clubs";
	cardStack[27] = "2 of Clubs";
	cardStack[28] = "3 of Clubs";
	cardStack[29] = "4 of Clubs";
	cardStack[30] = "5 of Clubs";
	cardStack[31] = "6 of Clubs";
	cardStack[32] = "7 of Clubs";
	cardStack[33] = "8 of Clubs";
	cardStack[34] = "9 of Clubs";
	cardStack[35] = "10 of Clubs";
	cardStack[36] = "Jack of Clubs";
	cardStack[37] = "Queen of Clubs";
	cardStack[38] = "King of Clubs";
	cardStack[39] = "Ace of Diamonds";
	cardStack[40] = "2 of Diamonds";
	cardStack[41] = "3 of Diamonds";
	cardStack[42] = "4 of Diamonds";
	cardStack[43] = "5 of Diamonds";
	cardStack[44] = "6 of Diamonds";
	cardStack[45] = "7 of Diamonds";
	cardStack[46] = "8 of Diamonds";
	cardStack[47] = "9 of Diamonds";
	cardStack[48] = "10 of Diamonds";
	cardStack[49] = "Jack of Diamonds";
	cardStack[50] = "Queen of Diamonds";
	cardStack[51] = "King of Diamonds";

	srand(time(0));
	string userEntry;
	string playingGame = "Yes";
	bool finish = false;


	ShuffleDeck(cardStack, 52);
	int currentCardIndex = 0;

	/*for (int i = 0; i < 52; i++) {
		cout << cardStack[i] << endl;
	}
	*/

	while (playingGame == "Yes") {

		
		int dealerTotal = 0;
		int playerTotal = 0;


		CardTotal(DealerDealt(cardStack, currentCardIndex, DECK_SIZE), dealerTotal);
		PrintScore(dealerTotal, "Dealer");
		CardTotal(PlayerDealt(cardStack, currentCardIndex, DECK_SIZE), playerTotal);
		CardTotal(PlayerDealt(cardStack, currentCardIndex, DECK_SIZE), playerTotal);
		PrintScore(playerTotal, "Your");
		if (playerTotal > 21) {
			cout << "You busted! You lose!" << endl;
			finish = true;
		}

		while (playerTotal <= 21) {
			if (playerTotal == 21) {
				cout << "Blackjack! You win!" << endl;
				finish = true;
				break;
			}
			else if (playerTotal > 21) {
				cout << "You busted! You lose!" << endl;
				finish = true;
				break;
			}
			cout << "Do you want to ""Hit"" or ""Stand""?" << endl << "> ";
			cin >> userEntry;

			if (userEntry == "Hit" || userEntry == "hit" || userEntry == "h" || userEntry == "H") {
				CardTotal(PlayerDealt(cardStack, currentCardIndex, DECK_SIZE), playerTotal);
				PrintScore(playerTotal, "Your");
				if (playerTotal == 21) {
					cout << "Blackjack! You win!" << endl;
					finish = true;
					break;
				}
				else if (playerTotal > 21) {
					cout << "You busted! You lose!" << endl;
					finish = true;
					break;
				}
				else {
					continue;
				}
			}
			else if (userEntry == "Stand" || userEntry == "stand" || userEntry == "s" || userEntry == "S") {
				break;
				break;
			}
			else {
				cout << endl << "Invaild Entry." << endl;
			}
		}


		while ((dealerTotal < 21) && (dealerTotal < playerTotal) && (finish == false) && (dealerTotal < 17)) {
			CardTotal(DealerDealt(cardStack, currentCardIndex, DECK_SIZE), dealerTotal);
			PrintScore(dealerTotal, "Dealer");
			if (dealerTotal == 21) {
				cout << "Dealer got a blackjack! You lose!" << endl;
				break;
			}
			else if (dealerTotal > 21) {
				cout << "Dealer busted! You win!" << endl;
				break;
			}
			else if (dealerTotal == playerTotal && dealerTotal > 17) {
				cout << "Tie! If you were playing with money, you would have gotten your bet back." << endl;
				break;
			}
			else if (dealerTotal > playerTotal && dealerTotal < 21) {
				cout << "Dealer got the higher score. You lose!" << endl;
				break;
			}
			else {
				continue;
			}
		}


		cout << "Do you want to play again? Yes or No?" << endl << "> ";
		cin >> playingGame;

		if (playingGame == "Yes") {
			finish = false;
			continue;
		}
		else if (playingGame == "No") {
			return 0;
		}
		else {
			cout << "Invaild Entry" << endl;
		}
	}

	return 0;
}