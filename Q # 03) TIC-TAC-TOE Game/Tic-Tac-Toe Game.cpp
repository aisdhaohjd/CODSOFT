#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << board[row][col];
            if (col < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (row < 2) {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {
                return false; // There's an empty space, so the game is not a draw yet
            }
        }
    }
    return true; // All spaces are filled, indicating a draw
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X';
    bool gameIsOver = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (!gameIsOver) {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
            gameIsOver = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "It's a draw! Good game!" << std::endl;
            gameIsOver = true;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
