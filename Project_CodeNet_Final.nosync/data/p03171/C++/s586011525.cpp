#include<bits/stdc++.h>
using namespace std;

int main(){
  long n;
  cin>>n;
  long arr[3000]; long sum=0;
  for(int i=0;i<n;i++){ cin>>arr[i]; sum+=arr[i];}
  long dp[3005][3005];
  for(int i=0;i<=3004;i++){
    for(int j=0;j<=3004;j++){
      dp[i][j]=0;
    }
  }
  for(int i=1;i<=n;i++) dp[i][i]=arr[i-1];
  for(int i=1;i<n;i++){
    for(int j=1;j<=n-i;j++){
      long a=arr[j-1]+min(dp[j+2][i+j],dp[j+1][i+j-1]);
      long b=arr[i+j-1]+min(dp[j][i+j-2],dp[j+1][i+j-1]);
        dp[j][i+j]=max(a,b);
      
    }
  }
  
   long ans=dp[1][n]-(sum-dp[1][n]);
  cout<<ans;
}
  
  
  
  