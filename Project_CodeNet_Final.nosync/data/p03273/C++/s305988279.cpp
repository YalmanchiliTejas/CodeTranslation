#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> board(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        bool comp = true;
        for (int j = 0; j < w; j++) {
            if (board[i][j] == '#') {
                comp = false;
                break;
            }
        }
        if (comp) {
            for (int j = 0; j < w; j++) {
                board[i][j] = ' ';
            }
        }
    }
    for (int j = 0; j < w; j++) {
        bool comp = true;
        for (int i = 0; i < h; i++) {
            if (board[i][j] == '#') {
                comp = false;
                break;
            }
        }
        if (comp) {
            for (int i = 0; i < h; i++) {
                board[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < h; i++) {
        bool newline = false;
        for (int j = 0; j < w; j++) {
            if (board[i][j] != ' ') {
                cout << board[i][j];
                newline = true;
            }
        }
        if (newline) {
            cout << endl;
        }
    }

    return 0;
}