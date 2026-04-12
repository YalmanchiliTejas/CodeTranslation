#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))

int h, w;
char f[10][10];
bool flag;

void bfs(int y, int x) {

    bool go = false;
    if (f[y][x] == '#' || f[y][x] == 'x') {
        f[y][x] = 'x';
        if (0 <= x + 1 && x + 1 < w) { bfs(y, x + 1); go = true; }
        if (0 <= y + 1 && y + 1 < h) { bfs(y + 1, x); go = true; }
    }

    if (!go) {
        bool ok = true;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (f[i][j] == '#') { ok = false; i = h; break; }
            }
        }

        if (ok) { flag = true; return; }
    }

    if (go) { f[y][x] = '#'; }

}

int main() {
    string y = "Possible", n = "Impossible";

    cin >> h >> w;
    rep(i, h) rep(j, w) cin >> f[i][j];


    bfs(0, 0);
    cout << (flag ? y : n) << endl;

    return 0;
}
