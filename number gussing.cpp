#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        int numberToGuess = rand() % 100 + 1; // Random number between 1 and 100
        int guess;
        int attempts = 0;

        cout << "========================================\n";
        cout << "  Welcome to the Number Guessing Game!\n";
        cout << "  I'm thinking of a number between 1 and 100.\n";
        cout << "========================================\n";

        bool guessedCorrectly = false;

        while (!guessedCorrectly) {
            cout << "Enter your guess: ";
            cin >> guess;

            // Handle invalid (non-integer) input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "That's not a valid number. Try again.\n";
                continue;
            }

            attempts++;

            if (guess < numberToGuess) {
                cout << "Too low! Try again.\n\n";
            } else if (guess > numberToGuess) {
                cout << "Too high! Try again.\n\n";
            } else {
                guessedCorrectly = true;
                cout << "\nCorrect! The number was " << numberToGuess << ".\n";
                cout << "You guessed it in " << attempts << " attempts.\n";
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing! Goodbye.\n";
    return 0;
}