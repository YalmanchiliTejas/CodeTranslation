// -----------------------------------
// Author     : MatsuTaku
// Affiliation: Tokushima University
// Country    : Japan
// Date       : 03/22/2020
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int N,S; cin>>N>>S;
  vector<ll> A(N); for(auto& a : A) cin>>a;

  ll ans = 0;
  vector<ll> dp(S+1);
  for (int i = 0; i < N; i++) {
    dp[0] = i+1;
    for (int s = S-A[i]; s >= 0; s--) {
      (dp[s+A[i]] += dp[s]) %= MOD;
    }
    (ans += dp[S]) %= MOD;
  }
  cout << ans << endl;

  return 0;
}
