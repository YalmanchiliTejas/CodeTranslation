#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=3001;
ll dp[N][N];
ll a[N];
ll solve(int i,int j)
{
  if(i>j)
    return 0;
  if(dp[i][j]!=LLONG_MIN)
    return dp[i][j];
  ll ans=a[i]-solve(i+1,j);
  ans=max(ans,a[j]-solve(i,j-1));
  return dp[i][j]=ans;
}
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   dp[i][j]=LLONG_MIN;
  cout<<solve(1,n)<<endl;
}