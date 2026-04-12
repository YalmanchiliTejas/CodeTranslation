// Nurbakyt Madibek
// Look at my code! IT'S AWESOME

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;

const int inf = (int)1e9 + 123;
const ll infl = (ll)1e18 + 123;
const double eps = 1e-9;

const int MAX_N = (int)1e5 + 5;
const int mod = (int)1e9 + 7;

int n, m;
char a[105][105];

int moves[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int dfs(int x, int y) {
    if (x == n && y == m) {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        int nx = x + moves[i][0], ny = y + moves[i][1];
        if (nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny] == '#') {
            cnt++;
        }
    }
    if (cnt != 1) {
        return -1;
    }
    for (int i = 0; i < 2; i++) {
        int nx = x + moves[i][0], ny = y + moves[i][1];
        if (nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny] == '#') {
            int res = dfs(nx, ny);
            if (res == -1)
                return res;
            return res + 1;
        }
    }
    assert(0);
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int v = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.')
                continue;
            v++;
        }
    if (a[1][1] == '#' && a[n][m] == '#' && dfs(1, 1) == v) {
        puts("Possible");
    }
    else
        puts("Impossible");
    return 0;
}
