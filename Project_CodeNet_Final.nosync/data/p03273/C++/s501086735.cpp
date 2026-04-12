#include <bits/stdc++.h>
using namespace std;

int main () {

    int H, W;
    cin >> H >> W;

    char a[H][W];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    bool h[H], w[W];
    fill(h, h + H, false); fill(w, w + W, false);

    for (int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                h[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (a[j][i] == '#') {
                w[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (h[i] && w[j]) {
                cout << a[i][j];
            }
        }
        if (h[i]) {
            cout << endl;
        }
    }

    return 0;
}