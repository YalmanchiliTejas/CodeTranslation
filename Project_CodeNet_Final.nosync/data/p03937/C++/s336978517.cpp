#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int h, w;
    cin >> h >> w;
    char f[10][10] = {};
    for (Int i = 0; i < h; i++) {
        for (Int j = 0; j < w; j++) {
            cin >> f[i][j];
        }
    }
    queue<pair<Int, Int>> q;
    q.push({0, 0});
    while (not q.empty()) {
        pair<Int, Int> p = q.front();
        q.pop();
        f[p.fi][p.se] = '.';
        Int dx[] = {1, 0};
        Int dy[] = {0, 1};
        for (Int i = 0; i < 2; i++) {
            Int ny = dy[i] + p.fi;
            Int nx = dx[i] + p.se;
            if (ny < 0 or ny == h or nx < 0 or nx == w) continue;
            if (f[ny][nx] == '.') continue;
            q.push({ny, nx});
            break;
        }
    }
    bool check = true;
    for (Int i = 0; i < h; i++) {
        for (Int j = 0; j < w; j++) {
            if (f[i][j] == '#') check = false;
        }
    }
    dump(not check ? "Impossible" : "Possible");
    return 0;
}
