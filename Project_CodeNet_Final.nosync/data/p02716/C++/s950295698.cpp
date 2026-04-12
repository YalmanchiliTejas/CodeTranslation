#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

const ll INF = 1e18;
ll dp[100005][3];

int main() {
  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  ll ans = -INF;
  if (n%2 == 0) {
    for (int i = 0; i < n/2; ++i) {
      dp[i+1][0] += dp[i][0] + A[i*2];
      dp[i+1][1] += dp[i][1] + A[i*2+1];
    }
    rep(i, n/2+1) ans = max(ans, dp[i][0]+dp[n/2][1]-dp[i][1]);
  } else {
    rep(i, n/2+1) rep(j, 3) dp[i][j] = -INF;
    rep(i, 3) dp[1][i] = A[i];
    for (int i = 1; i < n/2; ++i) {
      dp[i+1][0] = dp[i][0] + A[i*2];
      dp[i+1][1] = max(dp[i][0] + A[i*2+1], dp[i][1] + A[i*2+1]);
      rep(j, 3) dp[i+1][2] = max(dp[i+1][2], dp[i][j] + A[i*2+2]);
    }
    rep(i, 3) ans = max(ans, dp[n/2][i]);
  }
  cout << ans << endl;
  return 0;
}