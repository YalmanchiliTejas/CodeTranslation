#include "bits/stdc++.h"
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int sharp = 0;
    vector<vector<char>> A(10, vector<char>(10));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (A[i][j] == '#') {
                sharp++;
            }
        }
    }

    int x = 0;
    int y = 0;
    int move = 0;
    bool flag = true;
    while (x != H - 1 || y != W - 1) {
        if (A[x + 1][y] == '#' && A[x][y + 1] != '#') {
            x++;
        }
        else if (A[x + 1][y] != '#' && A[x][y + 1] == '#') {
            y++;
        }
        else {
            flag = false;
            break;
        }
    }

    if (flag) {
        if (sharp - 1 == x + y) {
            cout << "Possible" << endl;
        }
        else {
            cout << "Impossible" << endl;
        }
    }
    else {
        cout << "Impossible" << endl;
    }
}