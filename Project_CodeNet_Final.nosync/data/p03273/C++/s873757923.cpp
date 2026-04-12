#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

ll count(const vector<int>& vec) {
  vector<vector<vector<ll>>> dp(vec.size() + 1,
                                vector<vector<ll>>(2, vector<ll>(2, 0)));
  dp[0][0][0] = 1;

  // 桁 dp
  int cnt = 0;
  for (int i = 0; i < vec.size(); i++) {
    for (int d = 0; d < 10; d++) {
      for (int j = 0; j < 2; j++) {
        for (int l = 0; l < 2; l++) {
          // skip large number
          if (l == 0 && vec[i] < d) {
            continue;
          }
          int nj = (d == 4 || d == 9) ? 1 : j;
          int nl = (vec[i] > d) ? 1 : l;

          dp[i + 1][nj][nl] += dp[i][j][l];
        }
      }
    }
  }
  return dp[vec.size()][1][1] + dp[vec.size()][1][0];
}
int main() {
  ll H, W;
  cin >> H >> W;
  vector<vector<char>> mp(H, vector<char>(W));
  vector<bool> white_row(H);
  vector<bool> white_col(W);

  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      cin >> mp[i][j];
    }
  }

  for (ll i = 0; i < H; i++) {
    bool white = true;
    for (ll j = 0; j < W; j++) {
      if (mp[i][j] == '#') {
        white = false;
      }
    }
    white_row[i] = white;
  }

  for (ll j = 0; j < W; j++) {
    bool white = true;
    for (ll i = 0; i < H; i++) {
      if (mp[i][j] == '#') {
        white = false;
      }
    }
    white_col[j] = white;
  }

  for (ll i = 0; i < H; i++) {
    if (white_row[i]) {
      continue;
    }
    for (ll j = 0; j < W; j++) {
      if (white_col[j]) {
        continue;
      }
      cout << mp[i][j];
    }
    cout << endl;
  }
}