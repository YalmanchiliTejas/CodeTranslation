#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n,i,k,kotae=0;
  cin>>n;
  long long int dp[3][n];
  for(i=0;i<n;i++){
    dp[0][i]=0;
    dp[1][i]=0;
    dp[2][i]=0;
  }
  if(n%2==1){
    cin>>k;
    dp[0][0]=k;
    cin>>k;
    dp[1][1]=k;
    cin>>k;
    dp[0][2]=dp[0][0]+k;
    dp[2][2]=k;
    for(i=3;i<n;i++){
      cin>>k;
      if(i%2==0){
        dp[0][i]=dp[0][i-2]+k;
        dp[2][i]=max(max(dp[2][i-2],dp[1][i-3]),dp[0][i-4])+k;
      }else{
        dp[1][i]=max(dp[1][i-2],dp[0][i-3])+k;
      }
    }
    kotae=max(max(dp[2][n-1],dp[1][n-2]),dp[0][n-3]);
  }else{
    cin>>k;
    dp[0][0]=k;
    cin>>k;
    dp[1][1]=k;
    for(i=2;i<n;i++){
      cin>>k;
      if(i%2==0){
        dp[0][i]=dp[0][i-2]+k;
      }else{
        dp[1][i]=max(dp[1][i-2],dp[0][i-3])+k;
      }
    }
    kotae=max(dp[1][n-1],dp[0][n-2]);
  }
  cout<<kotae;
}