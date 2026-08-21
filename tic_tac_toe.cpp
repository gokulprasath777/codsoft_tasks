#include <iostream>
using namespace std;

char board[3][3];

// Initialize board with numbers 1-9 (helps players pick positions)
void initializeBoard() {
    int num = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '1' + (i * 3 + j);
}

// Display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Update board with player's move; returns false if invalid
bool updateBoard(int position, char playerSymbol) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = playerSymbol;
    return true;
}

// Check if the current player has won
bool checkWin(char playerSymbol) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol)
            return true;
        if (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol)
            return true;
    }
    // Check diagonals
    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
        return true;
    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
        return true;

    return false;
}

// Check if the board is full (draw)
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        initializeBoard();
        char currentPlayer = 'X';
        bool gameOver = false;

        cout << "========================================\n";
        cout << "         Tic-Tac-Toe Game\n";
        cout << "========================================\n";
        cout << "Players take turns entering a number (1-9)\n";
        cout << "corresponding to the board position.\n";

        while (!gameOver) {
            displayBoard();

            int position;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> position;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a number between 1 and 9.\n";
                continue;
            }

            if (!updateBoard(position, currentPlayer)) {
                cout << "Invalid move. That cell is either taken or out of range. Try again.\n";
                continue;
            }

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "🎉 Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        cout << "\n";
    }

    cout<<"Thanks for playing! Goodbye.\n";
return 0; 
}
