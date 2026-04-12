#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  vector<ll> dp(N, 0), dp2(N, 0);
  for (ll i = 0; i < N; i++) {
    if (N % 2) dp[i] = A[i];
    else dp[i] = -A[i];
  }
  dp2 = dp;

  for (ll len = 2; len <= N; len++) {
    for (ll l = 0; l + len - 1 < N; l++) {
      ll r = l + len - 1;
      ll al = dp2[l], ar = dp2[r];
      if ((N - len) % 2) {
        dp[l] = min(-A[l] + dp2[l + 1], -A[r] + dp2[l]);
      } else {
        dp[l] = max(A[l] + dp2[l + 1], A[r] + dp2[l]);
      }
    }
    dp2 = dp;
  }
  cout << dp[0] << '\n';
  return 0;
}