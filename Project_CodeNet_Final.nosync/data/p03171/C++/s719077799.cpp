#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

int main(){
  int n; cin >> n;
  int a[n];
  REP(i, n) cin >> a[i];

  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(2)));
  REP(i, n+1)REP(j, n+1){
    dp[i][j][0] = LLONG_MIN;
    dp[i][j][1] = LLONG_MAX;
  }

  function<ll(int, int, int)> rec = [&](int l, int r, int turn){
    if(l > r) return 0LL;
    if(turn == 0){
      if(dp[l][r][turn] != LLONG_MIN) return dp[l][r][turn];
      ll l_v = rec(l+1, r, 1-turn) + a[l];
      ll r_v = rec(l, r-1, 1-turn) + a[r];
      return dp[l][r][turn] = max(l_v, r_v);
    } else {
      if(dp[l][r][turn] != LLONG_MAX) return dp[l][r][turn];
      ll l_v = rec(l+1, r, 1-turn) - a[l];
      ll r_v = rec(l, r-1, 1-turn) - a[r];
      return dp[l][r][turn] = min(l_v, r_v);
    }
  };

  cout << rec(0, n-1, 0) << endl;

  return 0;
}
