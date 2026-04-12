#include <bits/stdc++.h>

using namespace std;

int main()
{
  string n;
  int k;
  cin>>n>>k;
  long long dp[n.length()+1][4][2]={0};
      dp[0][0][1]=1;
  for (int i=1;i<=n.length();i++)
  {
      for (int j=0;j<4;j++)
      {
          if (j!=0)
          dp[i][j][0]+=(9*dp[i-1][j-1][0]+max((n[i-1]-'0'-1),0)*dp[i-1][j-1][1]);
          dp[i][j][0]+=(dp[i-1][j][0]+(n[i-1]=='0' ? 0 : 1)*dp[i-1][j][1]);
          if (n[i-1]!='0' && j!=0)
          dp[i][j][1]+=dp[i-1][j-1][1];
          else
            if (n[i-1]=='0')
          dp[i][j][1]+=dp[i-1][j][1];
      }
  }
  cout<<dp[n.length()][k][0]+dp[n.length()][k][1];
    return 0;
}
