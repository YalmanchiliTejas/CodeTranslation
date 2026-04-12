#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int H,W; cin >> H >> W;
    vector<string> vec(H);
    for (int i = 0; i < H; i++) cin >> vec[i];
    vector<bool> row(H, false);
    vector<bool> col(W, false);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (vec[i][j] == '#') {
                row[i] = col[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        if (row[i]) {
            for (int j = 0; j < W; j++) {
                if (col[j]) cout << vec[i][j];
            }
            cout << endl;
        }
    }
}
