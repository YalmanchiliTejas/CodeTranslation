#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)x.size())
template <class T> bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

/*
 */

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int, int>;

int dp[105][2][5];

signed main() {
  string s;
  int K;
  cin >> s >> K;
  int n = sz(s);

  dp[0][0][0] = 1;
  rep(i, 0, n) rep(j, 0, 2) rep(k, 0, 5) {
    int d = j ? 9 : s[i] - '0';
    rep(x, 0, d + 1) {
      if (x != 0 and k == 4)
        continue;
      dp[i + 1][j || x < d][k + (x != 0)] += dp[i][j][k];
    }
  }

  int ans = dp[n][0][K] + dp[n][1][K];
  cout << ans << endl;

  return 0;
}
