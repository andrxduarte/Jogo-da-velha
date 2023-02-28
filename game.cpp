#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';

void draw_board() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool check_win() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

int main() {
    int row, col;
    bool game_over = false;

    while (!game_over) {
        draw_board();
        cout << "É a vez do jogador: " << player << ". Entre com a linha (1-3) e coluna (1-3): ";
        cin >> row >> col;
        row--; col--;

        if (board[row][col] != ' ') {
            cout << "Movimento inválido. Por favor, tente novamente." << endl;
            continue;
        }

        board[row][col] = player;
        if (check_win()) {
            game_over = true;
            cout << "Parabéns, " << player << " você ganhou!" << endl;
        }
        else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
                 board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
                 board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
            game_over = true;
            cout << "É um empate!" << endl;
        }
        else {
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    draw_board();
    return 0;
}
