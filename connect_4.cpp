//Connect Four Game in C++

#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;

void initialize(char board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = ' ';
        }
    }
}

void display(const char board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
    }
    for (int j = 0; j < COLUMNS; j++) {
        cout << "----";
    }
    cout << "-" << endl;
    for (int j = 0; j < COLUMNS; j++) {
        cout << "  " << j + 1 << " ";
    }
    cout << endl;
}

bool isFull(const char board[ROWS][COLUMNS], int column) {
    return board[0][column] != ' ';
}

bool dropDisc(char board[ROWS][COLUMNS], int column, char disc) {
    if (isFull(board, column)) {
        return false;
    }
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][column] == ' ') {
            board[i][column] = disc;
            return true;
        }
    }
    return false;
}

bool checkWin(const char board[ROWS][COLUMNS], char disc) {
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS - 3; j++) {
            if (board[i][j] == disc && board[i][j + 1] == disc && board[i][j + 2] == disc && board[i][j + 3] == disc) {
                return true;
            }
        }
    }
   
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == disc && board[i + 1][j] == disc && board[i + 2][j] == disc && board[i + 3][j] == disc) {
                return true;
            }
        }
    }
   
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS - 3; j++) {
            if (board[i][j] == disc && board[i - 1][j + 1] == disc && board[i - 2][j + 2] == disc && board[i - 3][j + 3] == disc) {
                return true;
            }
        }
    }
    
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLUMNS - 3; j++) {
            if (board[i][j] == disc && board[i + 1][j + 1] == disc && board[i + 2][j + 2] == disc && board[i + 3][j + 3] == disc) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char board[ROWS][COLUMNS];
    initialize(board);

    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;
    bool gameWon = false;
    int moveCount = 0;

    while (moveCount < ROWS * COLUMNS && !gameWon) {
        display(board);
        int column;
        cout << "Player " << currentPlayer << ", enter the column (1-" << COLUMNS << ") to drop your disc: ";
        cin >> column;
        if (column < 1 || column > COLUMNS || isFull(board, column - 1)) {
            cout << "Invalid move. Try again." << endl;
        } else {
            dropDisc(board, column - 1, currentPlayer);
            gameWon = checkWin(board, currentPlayer);
            if (gameWon) {
                display(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else {
                currentPlayer = (currentPlayer == player1) ? player2 : player1;
                moveCount++;
            }
        }
    }

    if (!gameWon) {
        display(board);
        cout << "It's a draw!" << endl;
    }

    return 0;
}
