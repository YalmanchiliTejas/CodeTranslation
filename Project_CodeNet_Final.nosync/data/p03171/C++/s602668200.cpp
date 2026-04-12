#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
const int MX=3000;
ll dp[MX+5][MX+5];
ll a[MX+5];
int n,k;
ll solve(int i, int j)
{
  if(i>j)return 0;
  if(~dp[i][j])return dp[i][j];
  ll mx;
  mx=max(a[i]-solve(i+1,j),a[j]-solve(i,j-1));
  return dp[i][j]=mx;
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  memset(dp,-1,sizeof(dp));
  ll res=solve(1,n);
  cout<<res<<endl;
  return 0;
}
