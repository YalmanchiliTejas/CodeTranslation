#include <bits/stdc++.h>
using namespace std;

inline void work(int H, int W) {
    char str[110];
    int b[110][110];
    for (int i = 0; i < H; ++ i) {
        scanf("%s", str);
        for (int j = 0; j < W; ++ j) {
            b[i][j] = (str[j] == '#' ? 1 : 0);
        }
    }
    bool h[110], w[110];
    memset(h, 0, sizeof(h));
    memset(w, 0, sizeof(w));
    for (int i = 0; i < H; ++ i) {
        for (int j = 0; j < W; ++ j) {
            if (b[i][j] == 1) {
                h[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < W; ++ i) {
        for (int j = 0; j < H; ++ j) {
            if (b[j][i] == 1) {
                w[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < H; ++ i) {
        if (h[i] == false) continue;
        for (int j = 0; j < W; ++ j) {
            if (w[j] == false) continue;
            cout << (b[i][j] == 1 ? '#' : '.');
        }
        cout << endl;
    }
}

int main() {
    int H, W;
    while (cin >> H >> W) {
        work(H, W);
    }
}
