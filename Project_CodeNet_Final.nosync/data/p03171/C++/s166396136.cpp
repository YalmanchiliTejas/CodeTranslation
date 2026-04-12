#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MIN 100000000000000

int main()
{
  int n;cin>>n;
  vector<ll> w(n);
  int i,j;
  rep(i,n)cin>>w[i];
  vector<vector<ll>> dp(n,vector<ll>(n,MIN));
  rep(i,n)
  {
    dp[i][i]=w[i];
  }
  for(i=1;i<=n-1;i++)
  {
    rep(j,n-i)
    {
      dp[j][j+i]=max(w[j]-dp[j+1][j+i],w[j+i]-dp[j][j+i-1]);
    }
  }
  cout<<dp[0][n-1]<<endl;
}
