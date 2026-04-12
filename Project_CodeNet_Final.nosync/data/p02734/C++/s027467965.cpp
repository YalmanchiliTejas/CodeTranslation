#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
const ll mod = 998244353;

int main(){
  int n, s; cin >> n >> s;
  vector<int> a(n);
  vector<vector<ll>> dp(n, vector<ll>(3005));
  rep(i, n) cin >> a[i];
  
  dp[0][0] = 2; dp[0][a[0]] = 1;
  rep(i, n){
    if(i==0) continue;
    rep(j, s+1){
      if(j == 0){ dp[i][0] = dp[i-1][0] + 1; continue;}
      if( j >= a[i] ) dp[i][j] = (dp[i-1][j] + dp[i-1][j-a[i]]) %mod;
      else dp[i][j] = dp[i-1][j];
    }
  }
  
  ll ans = 0;
  rep(i, n) ans = (ans + dp[i][s]) %mod;
  
  cout << ans << endl;

  return 0;
}
