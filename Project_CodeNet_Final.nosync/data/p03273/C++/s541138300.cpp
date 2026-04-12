#include <bits/stdc++.h>

#define INF 1e9
using namespace std;

int main() {

    int H, W; cin >> H >> W;

    vector<string> a(H);
    for (int i = 0; i < H; ++i) {
        cin >> a[i];
    }

    //黒いマスのある行、列を記録していく
    vector<bool> row(H, false);
    vector<bool> col(W, false);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (a[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    //黒いマスのある行、列を表示する
    for (int i = 0; i < H; ++i) {
        if (row[i]) {
            for (int j = 0; j < W; ++j) {
                if (col[j]) {
                    cout << a[i][j];
                }
            }

            cout << endl;
        }
    }
}