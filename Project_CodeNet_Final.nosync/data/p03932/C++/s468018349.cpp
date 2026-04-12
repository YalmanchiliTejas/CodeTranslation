#include <bits/stdc++.h>
typedef long long int ll;
#define FOR(i, a, b) for (ll i = (signed)(a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
ll h, w, grid[200][200], dp[500][200][200];
ll p[] = {1, 0, 0, 1, 1, 1, 0, 0};
int main() {
  cin >> h >> w;
  REP(i, h) {
    REP(j, w) { cin >> grid[i][j]; }
  }
  REP(i, h + w - 2) {
    REP(X, min(w, i + 1)) {
      REP(x, min(w, i + 1)) {
        if (h <= i - X || h <= i - x)
          continue;
        ll y = i - x, Y = i - X, cost = grid[Y][X] + grid[y][x];
        // cost -= (X == x && grid[y][x]);
        cost -= (X == x ? grid[y][x] : 0);
        REP(k, 4) {
          dp[i + 1][X + p[k * 2]][x + p[k * 2 + 1]] = max(
              dp[i + 1][X + p[k * 2]][x + p[k * 2 + 1]], cost + dp[i][X][x]);
        }
      }
    }
  }
  cout << dp[h + w - 2][w - 1][w - 1] + grid[h - 1][w - 1] << endl;
}
