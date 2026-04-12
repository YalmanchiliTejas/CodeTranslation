#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  int t,n,i,j,k=1e9+7,l=0;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++) cin>>a[i];
  int dp[n];
  dp[0]=a[0];
  for(i=1;i<n;i++) dp[i]=(dp[i-1]+a[i]);
  for(i=0;i<n-1;i++)
  {
    l=(l+(a[i]*((dp[n-1]-dp[i])%k+k)%k)%k)%k;
  }
  cout<<l;
}