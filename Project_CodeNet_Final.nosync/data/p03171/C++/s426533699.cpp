#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<ll> > dp(n + 1, vector<ll>(n + 1));

  rep(i, n) rep(l, n - i) {
    int r = l + i + 1;
    if ((n - i) % 2 == 1)
      dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1]);
    else
      dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1]);
  }

  cout << dp[0][n] << endl;
  return 0;
}