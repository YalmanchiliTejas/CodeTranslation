// -----------------------------------
// Author     : MatsuTaku
// Affiliation: Tokushima University
// Country    : Japan
// Date       : 04/05/2020
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int n; cin>>n;
  vector<int> A; for (int i = 0; i < n; i++) {
    int a; cin>>a;
    A.push_back(a);
  }

  vector<vector<ll>> dp(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    dp[i][i] = A[i]*(n%2==0?-1:1);
  }
  for (int d = 2; d <= n; d++) {
    for (int l = 0; l <= n-d; l++) {
      auto r = l+d-1;
      auto t = n-d;
      if (t%2==1) {
        dp[l][r] = min(dp[l][r-1]-A[r], dp[l+1][r]-A[l]);
      } else {
        dp[l][r] = max(dp[l][r-1]+A[r], dp[l+1][r]+A[l]);
      }
    }
  }
  cout << dp[0][n-1] << endl;

  return 0;
}
