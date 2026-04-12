#include<bits/stdc++.h>
using namespace std;
long long dp[3005][3005]; // left, len
long long arr[3005];
int main(){
  int n;cin>>n;
  long long sum = 0;
  for(int i=0;i<n;++i){
    cin>>arr[i];
    dp[i][1] = arr[i];
    dp[i][0] = 0;
    sum += arr[i];
  }
  for(int i=0;i+2<=n;++i){
    dp[i][2] = max(dp[i][1],dp[i+1][1]);
  }
  
  for(int len=3;len<=n;++len){
    for(int l=0;l+len<=n;++l){
      dp[l][len] = max(
        			arr[l] + min(dp[l+1][len-2],dp[l+2][len-2]),
        			arr[l+len-1] + min(dp[l+1][len-2],dp[l][len-2])
      				); 
    }
  }
  /*
  for(int i=0;i<=n;++i){
    for(int j=0;j+i<=n;++j){
    	cout<<dp[i][j]<<" ";  
    }
    cout<<endl;
  }
  
  cout<<endl;
  */
  cout<<2 * dp[0][n] - sum<<endl;
  return 0;
}