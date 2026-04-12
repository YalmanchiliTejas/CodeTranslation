#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MOD 998244353

int main()
{
  int n,s;cin>>n>>s;
  vector<int> a(n);
  int i,j,k;
  rep(i,n)cin>>a[i];
  vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(s+1,vector<ll>(3,0)));
  dp[0][0][0]=1;
  for(i=1;i<=n;i++)
  {
    for(j=0;j<=s;j++)
    {
      dp[i][j][0]=dp[i-1][j][0]%MOD;
      for(k=0;k<3;k++)
      {
        dp[i][j][k]=dp[i-1][j][k];
      }
      dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1])%MOD;
      if(j-a[i-1]>=0)dp[i][j][1]=(dp[i][j][1]+dp[i-1][j-a[i-1]][0]+dp[i-1][j-a[i-1]][1])%MOD;
      dp[i][j][2]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%MOD;
      if(j-a[i-1]>=0)dp[i][j][2]=(dp[i][j][2]+dp[i-1][j-a[i-1]][0]+dp[i-1][j-a[i-1]][1])%MOD;
    }
  }
  cout<<dp[n][s][2]<<endl;
}
