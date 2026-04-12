#include <bits/stdc++.h>
 
using namespace std;

int H;
int W; 

char M[10][10];
int X[10][10];

int N;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;

    for (int i = 0; i < H; ++i) {
        cin >> M[i];
    }

    N = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (M[i][j] == '#') {
                N++;
            }
        }
    }

    memset(X, 0, sizeof(X));
    X[0][0] = 1;

    bool b;

    while (true) {
        b = false;

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (i > 0 && M[i-1][j] == '#') {
                    if (X[i-1][j] + 1 > X[i][j]) {
                        X[i][j] = max(X[i][j], X[i-1][j]+1);
                        b = true;
                    }
                }

                if (j > 0 && M[i][j-1] == '#') {
                    if (X[i][j-1] + 1 > X[i][j]) {
                        X[i][j] = max(X[i][j], X[i][j-1]+1);
                        b = true;
                    }
                }
            }
        }

        if (!b) {
            break;
        }
    }

    if (X[H-1][W-1] == N) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
