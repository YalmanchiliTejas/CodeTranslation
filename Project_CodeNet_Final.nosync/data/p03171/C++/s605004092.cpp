#include<bits/stdc++.h>
using namespace std;
long long int find(vector<long long int>& ar,int l,int r,vector<vector<long long int>>& dp)
{
  if(l==r)
    return dp[l][r]=ar[l];
  if(l==r-1)
    return dp[l][r]=max(ar[l],ar[r]);
  if(l>r)
    return 0;
  
  if(dp[l][r]!=-1)
    return dp[l][r];
  
  return dp[l][r]=max((ar[l]+min(find(ar,l+2,r,dp),find(ar,l+1,r-1,dp))),(ar[r]+min(find(ar,l,r-2,dp),find(ar,l+1,r-1,dp))));
}
int main(){
 int n;
  cin>>n;
  vector<long long int> ar(n);
  vector<vector<long long int>> dp(n+1,vector<long long int>(n+1,-1));
  long long int sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>ar[i];
    sum+=ar[i];
  }
  long long int x=find(ar,0,n-1,dp);
  long long int y=sum-x;
  cout<<x-y;
}