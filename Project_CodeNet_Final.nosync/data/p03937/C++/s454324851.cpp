#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define SZ(x) ((int)(x).size())
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define UNIQUE(x) x.erase(unique(x.begin(), x.end()), x.end())

const static llong MOD = 1000000000 + 7;
const static llong INF = 1LL << 60;
const static double eps = 1e-6;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

int h, w;
char field[8][8];
bool visited[8][8];

void dfs(int i, int j) {
    visited[i][j] = true;
    if (i + 1 < h && visited[i + 1][j] != true && field[i + 1][j] == '#') dfs(i + 1, j);
    if (j + 1 < w && visited[i][j + 1] != true && field[i][j + 1] == '#') dfs(i, j + 1);
}

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    int cnt = 0;
    rep(i, h) {
        rep(j, w) {
            char a;
            cin >> a;
            if (a == '#') ++cnt;
        }
    }

    if (cnt == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}