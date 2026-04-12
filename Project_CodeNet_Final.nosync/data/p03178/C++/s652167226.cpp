/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

string s;
LL d,dp[100010][110],dp2[100010][110][2],res;

int main()
{
  cin>>s>>d;
  dp[0][0]=1;
  rep(i,s.size()-1)
  {
    rep(j,d)
    {
      if(dp[i][j]==0) continue;
      rep(k,10) dp[i+1][(j+k)%d]=(dp[i+1][(j+k)%d]+dp[i][j])%MOD;
    }
  }
  res=(dp[s.size()-1][0]-1+MOD)%MOD;
  dp2[0][0][0]=1;
  rep(i,s.size())
  {
    rep(j,d)
    {
      rep(k,2)
      {
        if(dp2[i][j][k]==0) continue;
        if(k==0)
        {
          for(int p=(i==0 ? 1:0);p<=s[i]-'0';p++)
          {
            if(p==s[i]-'0') dp2[i+1][(j+p)%d][0]=(dp2[i+1][(j+p)%d][0]+dp2[i][j][k])%MOD;
            else dp2[i+1][(j+p)%d][1]=(dp2[i+1][(j+p)%d][1]+dp2[i][j][k])%MOD;
          }
        }
        else
        {
          for(int p=(i==0 ? 1:0);p<10;p++)
          dp2[i+1][(j+p)%d][1]=(dp2[i+1][(j+p)%d][1]+dp2[i][j][k])%MOD;
        }
      }
    }
  }
  cout<<(dp[s.size()-1][0]-1+dp2[s.size()][0][0]+dp2[s.size()][0][1]+MOD)%MOD<<endl;
  return 0;
}