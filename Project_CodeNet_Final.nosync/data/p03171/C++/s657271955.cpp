#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n;cin >> n;
  vector<ll> v(n);
  vector<vector<ll>> dp(n+1,vector<ll>(n+1));
  for(ll i=0;i<n;i++) cin >> v[i];
  for(int i=n-1;i>=0;i--){
    for(int j = i;j<n;j++){
      if(i == j) dp[i][j] = v[i];
      else{
        dp[i][j] = max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
      }
    }
  }
  cout << dp[0][n-1] << endl;
  cin.get();cin.get();
}
