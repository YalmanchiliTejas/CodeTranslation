#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
#define ll long long
ll dp[3005][3005][2];
int a[3005];
int mod=1e9 +7;
#define MAX 1e18+5;
ll solve(int i,int j,int k)
{
  if(dp[i][j][k]!=-1)
    return dp[i][j][k];
  else if(i==j)
  {
    if(k==0)
      dp[i][j][k]=a[i];
    else
      dp[i][j][k]=-a[i];
  }
  else
  {
    if(k==0)
      dp[i][j][k]=max(a[i]+solve(i+1,j,!k),a[j]+solve(i,j-1,!k));
    else
      dp[i][j][k]=min(-a[i]+solve(i+1,j,!k),-a[j]+solve(i,j-1,!k));
  }
  return dp[i][j][k];
}
int main()
{
  fin;
  int n,i,j;
  cin>>n;
  for(i=0;i<n;i++)
    cin>>a[i];
  memset(dp,-1,sizeof(dp));
  cout<<solve(0,n-1,0);
}
