#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long dp[3005][3005];
long solve(int i,int j,int a[]){
  if(i==j)
    return a[i];
  if(i>j)
    return 0;
  if(dp[i][j]!=-1)
    return dp[i][j];
  dp[i][j]=max(a[i]-solve(i+1,j,a),a[j]-solve(i,j-1,a));
  return dp[i][j];
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<solve(0,n-1,a)<<endl;
}