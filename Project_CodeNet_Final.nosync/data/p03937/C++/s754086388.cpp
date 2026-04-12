#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;  cin >> H >> W;
    vector<vector<char>> grid(H + 1, vector<char>(W + 1));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> grid[i][j];

    int i = 0, j = 0;
    bool ok = true;
    while (true) {
        grid[i][j] = '.';
        if (i == H - 1 && j == W - 1) break;
        if (grid[i + 1][j] == '#') ++i;
        else if (grid[i][j + 1] == '#') ++j;
        else {
            ok = false;
            break;
        }
    }

    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) {
        if (grid[i][j] == '#') ok = false;
    }

    cout << (ok ? "Possible" : "Impossible") << endl;
}
