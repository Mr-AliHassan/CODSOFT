#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard (const vector < vector < char > > & board) {
    cout << "  0 1 2\n"; // Column indices
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the game is won by a player
bool checkWin (const vector < vector < char > > & board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw (const vector < vector < char > > & board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '-') return false; // If any cell is empty, game is not a draw
        }
    }
    return true; // All cells are filled, game is a draw
}


int main() {
    vector < vector < char > > board(3, vector < char > (3, '-')); // Initialize the game board
    char currentPlayer = 'X'; // Start with player X

    // Game loop
    while (true) {
        cout << "Current board:\n";
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        int row, col;
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check for win
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for draw
        if (checkDraw(board)) {
            cout << "It's a draw!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

