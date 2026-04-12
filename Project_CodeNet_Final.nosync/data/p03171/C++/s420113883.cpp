#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int n;
  cin>>n;
  int a[n+1];
  ll dp[n+1];
  for(int i=0;i<=n;i++) dp[i] = 0;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=n;i>=1;i--)
  {
    for(int j=i;j<=n;j++)
    {
      if(i == j)
      {
        dp[i] =  a[i];
      }
      else
      {
        dp[j] = max(a[i]-dp[j],a[j]-dp[j-1]);
      }
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}