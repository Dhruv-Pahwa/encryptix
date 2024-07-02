#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << "Current board state:" << endl;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool isValidMove(const vector<vector<char>>& board, int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-';
}

void updateBoard(vector<vector<char>>& board, int row, int col, char player) {
    board[row][col] = player;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playTicTacToe() {
    vector<vector<char>> board(3, vector<char>(3, '-'));
    char currentPlayer = 'X';
    bool gameEnded = false;

    while (!gameEnded) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (isValidMove(board, row, col)) {
            updateBoard(board, row, col, currentPlayer);

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnded = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw!" << endl;
                gameEnded = true;
            } else {
                switchPlayer(currentPlayer);
            }
        } else {
            cout << "Invalid move
