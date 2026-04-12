// -----------------------------------
// Author     : MatsuTaku
// Country    : Japan
// Created    : 04/12/20 20:48:37
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  constexpr ll MINF = -1e15;

  int n; cin>>n;
  vector<ll> A(n); for(auto& a:A) cin>>a;
  vector<array<ll, 2>> dp(n);
  dp[0] = {A[0], 0};
  dp[1] = {max(A[0], A[1]), MINF};
  for (int i = 2; i < n; i++) {
    if (i%2==0) {
      dp[i][0] = dp[i-2][0]+A[i];
      dp[i][1] = max(dp[i-1][0], dp[i-2][1]+A[i]);
    } else {
      dp[i][0] = max(dp[i-1][0], dp[i-2][0]+A[i]);
      dp[i][1] = MINF;
    }
    cerr<<dp[i][0]<<" "<<dp[i][1]<<endl;
  }
  auto ans = dp[n-1][n%2];
  cout << ans << endl;

  return 0;
}
