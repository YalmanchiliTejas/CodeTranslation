#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int, int>
#define F first
#define S second

const ll mod = 1000000007LL;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; i++) cin >> a[i];

  ll dp[n + 1][n + 1];  // Maximum sum of X - Y for this subarray
  memset(dp, 0, sizeof(dp));
  for (int i = n; i >= 1; i--) {
    for (int j = i; j <= n; j++) {
      if (i == j) {
        dp[i][j] = a[i];
        continue;
      }
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
    }
  }
  cout << dp[1][n];
}

int main(int argc, char const *argv[]) {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T = 1;
  while (T--) {
    solve();
  }

  return 0;
}