#include "bits/stdc++.h"
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    vector<bool> flagH(H);
    vector<bool> flagW(W);
    for (int i = 0; i < H; i++) {
        flagH[i] = false;
    }
    for (int i = 0; i < W; i++) {
        flagW[i] = false;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                flagH[i] = true;
                flagW[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        if (flagH[i]) {
            for (int j = 0; j < W; j++) {
                if (flagW[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}