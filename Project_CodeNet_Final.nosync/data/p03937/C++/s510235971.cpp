#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<string> field;

bool isInside(int ch, int cw) {
    return ch >= 0 && ch < H && cw >= 0 && cw < W;
}

void dfs(int ch, int cw) {
    field[ch][cw] = '.';
    if (ch == H - 1 && cw == W - 1) return;
    if (isInside(ch, cw + 1) && field[ch][cw + 1] == '#') dfs(ch, cw + 1);
    else if (isInside(ch + 1, cw) && field[ch + 1][cw] == '#') dfs(ch + 1, cw);
}

bool solve() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (field[i][j] == '#') return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    field = vector<string>(H);
    for (int i = 0; i < H; i++) {
        cin >> field[i];
    }
    dfs(0, 0);
    if (solve()) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}