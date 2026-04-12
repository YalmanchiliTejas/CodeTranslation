#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    char g[h][w];
    rep(y, h) rep(x, w) cin >> g[y][x];

    int rm_col[h] = {0}, rm_row[w] = {0};
    rep(y, h) {
        bool rm = true;
        rep(x, w) if (g[y][x] == '#') rm = false;
        if (rm) rm_col[y] = 1;
    }
    rep(x, w) {
        bool rm = true;
        rep(y, h) if (g[y][x] == '#') rm = false;
        if (rm) rm_row[x] = 1;
    }

    rep(y, h) {
        if (rm_col[y]) continue;
        rep(x, w) {
            if (rm_row[x]) continue;
            cout << g[y][x];
        }
        cout << endl;
    }

    return 0;
}
