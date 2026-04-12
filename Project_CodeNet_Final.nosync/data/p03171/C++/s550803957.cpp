#include<bits/stdc++.h>
using namespace std;
//dp[l][r]->(x-y)in the range l to r both inclusive
 
int main()
{
  int n;
  cin>>n;
  vector<long long> v(n);
  for(long long &x:v)
  cin>>x;
  vector<vector<long long>> dp(n,vector<long long>(n,INT_MIN));
  for(int d=0;d<=n-1;d++)
  {
      for(int l=0;l<n-d;l++)
      {
          int r=l+d;
          if(l==r)
          dp[l][r]=v[l];
          else
          dp[l][r]=max(v[l]-dp[l+1][r],v[r]-dp[l][r-1]);
      }
  }
  cout<<dp[0][n-1]<<endl;
  return 0;
}