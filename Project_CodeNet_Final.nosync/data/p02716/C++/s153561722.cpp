#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll INF = 1e15;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];
  vector<vector<ll>> dp(2, vector<ll>(2, -INF));

  dp[0][0] = 0;
  dp[1][1] = A[0];
  for (ll i = 1; i < N; i++) {
    vector<vector<ll>> dp2(2, vector<ll>(2, -INF));
    if (N & 1) {
      if (i & 1) {
        dp2[0][0] = max(dp[0][0], dp[0][1]);
        dp2[1][0] = max(dp[1][0], dp[1][1]);
        dp2[1][1] = dp[0][0] + A[i];
      } else {
        dp2[0][0] = max(dp[1][0], dp[1][1]);
        dp2[0][1] = dp[0][0] + A[i];
        dp2[1][1] = dp[1][0] + A[i];
      }
    } else {
      if (i & 1) {
        dp2[0][0] = max(dp[1][0], dp[1][1]);
        dp2[0][1] = dp[0][0] + A[i];
      } else {
        dp2[0][0] = max(dp[0][0], dp[0][1]);
        dp2[1][1] = dp[0][0] + A[i];
      }
    }
    dp = dp2;
  }

  cout << max(dp[0][0], dp[0][1]) << '\n';
  return 0;
}