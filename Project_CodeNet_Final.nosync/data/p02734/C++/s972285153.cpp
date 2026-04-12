#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
const int n_max=3010;
ll dp[n_max][n_max][3];
const int mod = 998244353;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n,s;
  cin >> n >> s;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  dp[0][0][0]=1;
  rep1(i,n){
    rep(l,s+1){
      dp[i][l][0] += dp[i-1][l][0];
      dp[i][l][1] += dp[i-1][l][0] + dp[i-1][l][1];
      dp[i][l][2] += dp[i-1][l][0] + dp[i-1][l][1] + dp[i-1][l][2];
      if(l+a[i-1] <= s){
	dp[i][l+a[i-1]][1] += dp[i-1][l][0] + dp[i-1][l][1];
	dp[i][l+a[i-1]][2] += dp[i-1][l][0] + dp[i-1][l][1];
      }
      rep(j,3)dp[i][l][j] %= mod;
    }
    //    cout << dp[i][s][2] << endl;
  }
  cout << dp[n][s][2] << endl;
  
  return 0;
    

}
