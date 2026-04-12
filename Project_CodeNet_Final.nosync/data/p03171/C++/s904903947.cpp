#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int N;
ll a[3000];

ll dp[3000][3000][2];

ll dfs(int left, int right, bool turn)
{
    if (dp[left][right][turn] != -1) {
        return dp[left][right][turn];
    }
    else if (left == right) {
        ll X = 0, Y = 0;
        if (turn) X += a[left];
        else Y += a[left];
        dp[left][right][turn] = X - Y;
        return X - Y;
    }
    else {
        if (turn) {
            ll sl = a[left] + dfs(left + 1, right, !turn);
            ll sr = a[right] + dfs(left, right - 1, !turn);
            ll s = max(sl, sr);
            dp[left][right][turn] = s;
            return s;
        }
        else {
            ll sl = dfs(left + 1, right, !turn) - a[left];
            ll sr = dfs(left, right - 1, !turn) - a[right];
            ll s = min(sl, sr);
            dp[left][right][turn] = s;
            return s;
        }
    }
}

int main(int argc, char **argv)
{
    cin >> N;
    REP(i, N) cin >> a[i];

    REP(i, 3000) REP(j, 3000) REP(k, 2) dp[i][j][k] = -1;

    cout << dfs(0, N - 1, true) << endl;

    return 0;
}
