#include <iostream>
#include <vector>

using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if any player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check if the board is full (draw)
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function to make a move
bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (board[row][col] != ' ') {
        return false;  // Cell is already occupied
    }
    board[row][col] = player;
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));  // Initialize the board with empty spaces
    char currentPlayer = 'X';

    while (true) {
        drawBoard(board);

        // Get the move from the current player
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        row = row-1;
        col = col-1;

        // Validate the move
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make the move
        if (!makeMove(board, row, col, currentPlayer)) {
            cout << "Invalid move. Cell is already occupied. Try again." << endl;
            continue;
        }

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if it's a draw
        if (checkDraw(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    drawBoard(board);

    return 0;
}
