#include <stdio.h>
#include <stdbool.h>

int board[8][8];

void print_board()
{
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            printf("%c", (board[row][col] == 1) ? '*' : '.');
        }
        printf("\n");
    }
}

/* place a queen in row row */
bool backtrack(int row)
{
    for (int col = 0; col < 8; ++col) {
        bool conflict = false;
        /* check all rows in 'col' for a queen */
        for (int irow  = 0; irow < 8; ++irow) {
            if (board[irow][col] != 0) {
                conflict = true;
                break;
            }
        }
        if (conflict) continue;
        /* check left upper diagonal */
        for (int k = row, l = col; k >= 0 && l >= 0; --k, --l) {
            if (board[k][l] != 0) {
                conflict = true;
                break;
            }
        }
        if (conflict) continue;
        /* check right upper diagonal */
        for (int k = row, l = col; k >= 0 && l < 8; --k, ++l) {
            if (board[k][l] != 0) {
                conflict = true;
                break;
            }
        }
        if (conflict) continue;
         /* check left lower diagonal */
        for (int k = row, l = col; k < 8 && l >= 0; ++k, --l) {
            if (board[k][l] != 0) {
                conflict = true;
                break;
            }
        }
        if (conflict) continue;
         /* check right lower diagonal */
        for (int k = row, l = col; k < 8 && l < 8; ++k, ++l) {
            if (board[k][l] != 0) {
                conflict = true;
                break;
            }
        }
        if (conflict) continue;
        /* we can place the queen */
        board[row][col] = 1;
        if (row == 7 || backtrack(row + 1)) {
            return true;
        }
        board[row][col] = 0;
    }
    return false;
}

int main()
{
    backtrack(0);
    print_board();
}
