#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
const ll INF = 100100100100;
 
int main(){
  int n; cin >> n;
  vector<ll> a(n);
  vector<vector<ll>> dp(n, vector<ll>(3, -INF));
  rep(i, n) cin >> a[i];
  dp[0][0] = a[0]; dp[1][0] = a[1];
  if(n>=3){
    dp[2][0] = dp[0][0] + a[2];
    dp[2][1] = a[2];
  }
  
  for(int i=3; i<n; i++){
    dp[i][0] = dp[i-2][0] + a[i];
    dp[i][1] = max( dp[i-3][0] + a[i], dp[i-2][1] +a[i]);
    dp[i][2] = max( dp[i-3][1] + a[i], dp[i-2][2] +a[i]);
    }
  
  ll ans;
  if(n%2==0) ans = max( dp[n-2][0], max( dp[n-1][0], dp[n-1][1]));
  else{
  ans = max( dp[n-3][0], max( dp[n-2][0], max( dp[n-2][1], max(dp[n-1][1], dp[n-1][2])))); 
  }
  cout << ans << endl;


  return 0;
}
