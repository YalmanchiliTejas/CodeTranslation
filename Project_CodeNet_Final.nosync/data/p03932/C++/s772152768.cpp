#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <complex>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

const int MN = 220;
int h, w;
ll g[MN][MN];

bool bc(int x, int y) {
    return (0 <= x && x < w && 0 <= y && y < h);
}


ll dp[2*MN][MN][MN];
bool used[2*MN][MN][MN] = {};

ll solve(int d, int ax, int bx) {
    int ay = d-ax, by = d-bx;
    if (!bc(ax, ay) || !bc(bx, by)) return -TEN(15);
    if (d == h+w-2) return g[ay][ax];
    if (used[d][ax][bx]) return dp[d][ax][bx];
    used[d][ax][bx] = true;
    ll &ans = dp[d][ax][bx];
    ans = -TEN(15);
    ans = max(ans, solve(d+1, ax, bx));
    ans = max(ans, solve(d+1, ax+1, bx));
    ans = max(ans, solve(d+1, ax, bx+1));
    ans = max(ans, solve(d+1, ax+1, bx+1));
    ans += g[ay][ax] + g[by][bx];
    if (ax == bx) {
        ans -= g[ay][ax];
    }
    return ans;
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
        }
    }
    cout << solve(0, 0, 0) << endl;
    return 0;
}

