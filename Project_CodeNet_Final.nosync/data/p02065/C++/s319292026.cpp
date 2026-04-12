#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int n,k,m;
  cin>>n>>k>>m;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  } else if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  vector<vector<ll>> dp(2*n+1, vector<ll>(1<<k, 0));
  vector<vector<ll>> dpzero(2*n+1, vector<ll>(k+1, 0));
  dpzero[2][1] = 1;
  ll bit = 2;
  FOR(i,1,k+1) {
    if (i >= n) break;
    dp[2+i][bit] = 1;
    bit |= 1;
    bit <<= 1;
  }
  FOR(i,2,2*n) {
    REP(j,(1<<k)-1) {
      if (j != 0) {
        ll nb = j << 1;
        int d = 0;
        REP(l,k+1) {
          if ((nb >> l) & 1) d = l;
        }
        ll nb2 = nb ^ (1 << d);
        if (nb2 == 0) {
          dpzero[i+1][d] += dp[i][j];
          dpzero[i+1][d] %= m;
        } else {
          dp[i+1][nb2] += dp[i][j];
          dp[i+1][nb2] %= m;
        }
        if (d == k) continue;
        nb |= 1;
        dp[i+1][nb] += dp[i][j];
        dp[i+1][nb] %= m;
      } else {
        FOR(l,1,k) {
          dp[i+1][1] += dpzero[i][l];
          dp[i+1][1] %= m;
        }
      }
    }
  }
  ll sum = 0;
  REP(i,k+1) {
    sum += dpzero[2*n][i];
    sum %= m;
  }
  cout<<sum<<endl;
  return 0;
}

