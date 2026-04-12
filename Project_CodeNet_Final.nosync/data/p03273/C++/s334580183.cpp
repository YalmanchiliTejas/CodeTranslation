#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<bool> Row(H, false), Column(W, false);
    string board[H];

    for(int i=0; i<H; i++) {
        cin >> board[i];
    }

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(board[i][j] == '#') {
                Column[j] = true;
                Row[i] = true;
            }
        }
    }

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(Column[j] && Row[i]) {
                cout << board[i][j];
            }
        }
        if(Row[i]) {
            cout << endl;
        }
    }
}