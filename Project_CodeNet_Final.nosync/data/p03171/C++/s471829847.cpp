#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<int>a(n);
  rep(i, n)cin>>a[i];
  ll dp[3001][3001];
  memset(dp, 0, sizeof(dp));

  rep(i, n)dp[i][i]=0;

  for(int len = 1; len<=n; len++){
    for(int l=0; l+len <= n; l++){
      int r = l+len;

      if((n-len)%2==0) dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
      else dp[l][r] = min(dp[l+1][r]-a[l], dp[l][r-1] - a[r-1]);
    }
  }

  cout<<dp[0][n]<<endl;

//rep(i,n)cout<<dp[0][i+1]<<' ';

  return 0;
}