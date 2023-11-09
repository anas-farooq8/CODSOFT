#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j == 0 || j == 1) cout << " | ";
        }
        cout << endl;
        if (i == 0 || i == 1) cout << "---------\n";
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Columns
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Diagonal from top-left to bottom-right
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Diagonal from top-right to bottom-left
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false; // If there is an empty cell, the game is not a draw
        }
    }
    return true; // All cells are filled, and no player has won
}

int main(int argc, char** argv) {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X'; // Start with player X
    bool gameOver = false;

    cout << "Tic-Tac-Toe Game" << endl;
    displayBoard(board);

    while (!gameOver) {
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;
        displayBoard(board);

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (checkDraw(board)) {
            cout << "It's a draw!" << endl;
            gameOver = true;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
