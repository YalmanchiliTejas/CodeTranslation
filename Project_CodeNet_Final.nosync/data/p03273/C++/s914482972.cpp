#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;  cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> grid[i][j];

    vector<int> gyou(H), retsu(W);
    // 行
    for (int i = 0; i < H; ++i) {
        bool flg = true;
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == '#') flg = false;
        }
        if (!flg) gyou[i] = 1;
        else gyou[i] = 0;
    }
    // 列
    for (int j = 0; j < W; ++j) {
        bool flg = true;
        for (int i = 0; i < H; ++i) {
            if (grid[i][j] == '#') flg = false;
        }
        if (!flg) retsu[j] = 1;
        else retsu[j] = 0;
    }

    for (int i = 0; i < H; ++i) {
        if (gyou[i] == 0) continue;
        for (int j = 0; j < W; ++j) {
            if (retsu[j] == 0) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }
}
