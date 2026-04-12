#include<bits/stdc++.h>

using namespace std;
long long dp[3005][3005];
long long calc(long long a[], int l, int r)
{
  if(l>r)
    return 0;
  if(dp[l][r]!=-1)
    return dp[l][r];
  return dp[l][r]=max(a[l]+min(calc(a,l+2,r),calc(a,l+1,r-1)),a[r]+min(calc(a,l+1,r-1),calc(a,l,r-2)));
}

int main()
{
  int n;
  cin>>n;
  long long a[n],s=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    s+=a[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<2*calc(a,0,n-1)-s<<endl;
  return 0;
}
