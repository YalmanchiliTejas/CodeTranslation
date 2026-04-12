#include <bits/stdc++.h>

#define int long long
#define forn(i, q, n) for (int i = q; i < n; ++i)
#define fr first
#define sc second
#define all(x), x.begin(), x.end()
#define endl '\n'
#define pb push_back

using namespace std;
const int MAXN = 3e5 + 1, INF = 1e9 + 11, MOD = 1e9 + 7;
const double EPS = 1e-9;

int masi[] = {0, 1};
int masj[] = {1, 0};
int usd[10][10];
vector<vector<char>> mas(12, vector<char>(12));

void dfs(int i, int j) {
    usd[i][j] = 1;
    forn(k, 0, 2) {
        if (mas[i + masi[k]][j + masj[k]] == '#') {
            dfs(i + masi[k], j + masj[k]);
            break;
        }
    }
}

main() {
//    freopen("treepathadd.in", "r", stdin);
//    freopen("treepathadd.out", "w", stdout);
//    freopen("input.txt", "r", stdin);
    int h, w;
    cin >> h >> w;
    forn(i, 1, h + 1)
        forn(j, 1, w + 1)
            cin >> mas[i][j];
    int i = 1, j = 1;
    dfs(i, j);
    if (mas[1][1] != '#' || !usd[h][w])
        return 0 * printf("Impossible");
    forn(i, 1, h + 1)
        forn(j, 1, w + 1)
            if (mas[i][j] == '#' && !usd[i][j])
                return 0 * printf("Impossible");
    printf("Possible");
}
