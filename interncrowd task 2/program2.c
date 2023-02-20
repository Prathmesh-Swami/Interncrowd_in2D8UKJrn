#include <stdio.h>

#define SIZE 3

// Function to print the game board
void print_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("-+-+-\n");
        }
    }
}

// Function to check if the game has been won
int check_win(char board[SIZE][SIZE], char symbol) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    // No win
    return 0;
}

int main() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int moves = 0;
    int row, col;
    char symbol = 'X';
    while (1) {
        printf("Player %c's turn\n", symbol);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        row--;
        col--;
        if (board[row][col] == ' ') {
            board[row][col] = symbol;
            moves++;
            print_board(board);
            if (check_win(board, symbol)) {
                printf("Player %c wins!\n", symbol);
                break;
            }
            if (moves == SIZE * SIZE) {
                printf("Tie game\n");
                break;
            }
            symbol = symbol == 'X' ? 'O' : 'X';
        } else {
            printf("That position is already taken\n");
        }
    }
    return 0;
}
