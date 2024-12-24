#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string cardNames[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
int cardScores[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

// Function to draw a random card
int drawCard(void) {
    return rand() % 13 + 1; // Random number between 1 and 13
}

// Function to calculate the score of cards
int calScore(int x, int y, int z) {
    int score_x = cardScores[x];
    int score_y = cardScores[y];
    int score_z = cardScores[z];
    return (score_x + score_y + score_z) % 10;
}

// Function to determine Yugi's action
int findYugiAction(int s) {
    if (s == 9) return 2; // Stay
    else if (s < 6) return 1; // Destiny draw
    else {
        return (rand() % 100 < 69) ? 1 : 2; // 69% chance to draw, 31% chance to stay
    }
}

// Function to check the winner
void checkWinner(int p, int y) {
    cout << "\n---------------------------------\n";
    if (p == y)
        cout << "|             Draw!!!           |\n";
    else if (p > y)
        cout << "|         Player wins!!!        |\n";
    else
        cout << "|          Yugi wins!!!         |\n";
    cout << "---------------------------------\n";
}

int main() {
    srand(time(0)); // Seed random number generator

    int playerScore, yugiScore, playerAction, yugiAction;
    int playerCards[3] = {drawCard(), drawCard(), 0}; // Player's cards
    int yugiCards[3] = {drawCard(), drawCard(), 0};   // Yugi's cards

    // Player's turn
    cout << "---------ORE NO TURN, DRAW!!!------------\n";
    cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
    playerScore = calScore(playerCards[0], playerCards[1], playerCards[2]);
    cout << "Your score: " << playerScore << "\n";

    do {
        cout << "(1) Destiny draw (2) Stay, SELECT: ";
        cin >> playerAction;
    } while (playerAction != 1 && playerAction != 2);

    if (playerAction == 1) {
        playerCards[2] = drawCard();
        playerScore = calScore(playerCards[0], playerCards[1], playerCards[2]);
        cout << "Player draws the 3rd card!!!" << "\n";
        cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
        cout << "Your new score: " << playerScore << "\n";
    }
    cout << "------------ Turn end -------------------\n\n";

    // Yugi's turn
    cout << "---------YUGI'S TURN, DRAW!!!------------\n";
    cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
    yugiScore = calScore(yugiCards[0], yugiCards[1], yugiCards[2]);
    cout << "Yugi's score: " << yugiScore << "\n";

    yugiAction = findYugiAction(yugiScore);
    if (yugiAction == 1) {
        yugiCards[2] = drawCard();
        yugiScore = calScore(yugiCards[0], yugiCards[1], yugiCards[2]);
        cout << "Yugi draws the 3rd card!!!\n";
        cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << "\n";
        cout << "Yugi's new score: " << yugiScore << "\n";
    }
    cout << "------------ Turn end -------------------\n";

    // Check the winner
    checkWinner(playerScore, yugiScore);

    return 0;
}
