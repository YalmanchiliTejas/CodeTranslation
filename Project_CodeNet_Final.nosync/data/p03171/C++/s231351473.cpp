#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli dp[3001][3001];
lli solve(int i, int j, int arr[]){
  if(dp[i][j]!=-1)
    return dp[i][j];
  if(i==j)
    return dp[i][j]=arr[i];
  return dp[i][j]=max(arr[i]-solve(i+1,j,arr),(arr[j]-solve(i,j-1,arr)));
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  memset(dp,-1,sizeof(dp));
  cout<<solve(0,n-1,arr)<<"\n";
   return 0;
}