#include <iostream>
using namespace std;

// Function prototypes
void drawBoard(char board[]);
bool checkWin(char board[], char player);
bool isBoardFull(char board[]);

int main() {
    // Initialize board
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player = 'X';
    int choice;
    bool gameOver = false;

    while (!gameOver) {
        // Draw the board
        drawBoard(board);

        // Player input
        cout << "Player " << player << ", enter the number of the cell where you want to place your mark: ";
        cin >> choice;

        // Validate the choice
        if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Update the board with the player's choice
        board[choice - 1] = player;

        // Check if the current player won
        if (checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!\n";
            gameOver = true;
        } else if (isBoardFull(board)) {
            // If the board is full and there's no winner, it's a draw
            drawBoard(board);
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            // Switch player
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

// Function to draw the Tic-Tac-Toe board
void drawBoard(char board[]) {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

// Function to check if a player has won the game
bool checkWin(char board[], char player) {
    // Check rows, columns, and diagonals
    return (
        (board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)
    );
}

// Function to check if the board is full
bool isBoardFull(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}
