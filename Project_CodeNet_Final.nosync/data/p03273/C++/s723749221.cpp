#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> grid(H);
  rep(i, H) { cin >> grid[i]; }

  int cx = 0;
  rep(i, H) {
    bool white = true;
    rep(j, W) { white = white && (grid[i][j] == '.'); }

    rep(j, W) { grid[cx][j] = grid[i][j]; }

    if (!white) {
      cx++;
    }
  }

  int cy = 0;
  rep(j, W) {
    bool white = true;
    rep(i, cx) { white = white && (grid[i][j] == '.'); }

    rep(i, cx) { grid[i][cy] = grid[i][j]; }

    if (!white) {
      cy++;
    }
  }

  rep(i, cx) {
    rep(j, cy) { cout << grid[i][j]; }
    cout << "\n";
  }

  return 0;
}