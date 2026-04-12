#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,a[3005],t;
  ll dp[3005][3005]={},s;
  
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  
  for (i=0;i<n;i++) dp[i][i+1]=a[i]*(n%2*2-1);
  
  for (t=2;t<=n;t++){
    for (i=0;i+t<=n;i++){
      if ((n+t)%2==0) s=max(dp[i+1][i+t]+a[i],dp[i][i+t-1]+a[i+t-1]);
      else s=min(dp[i+1][i+t]-a[i],dp[i][i+t-1]-a[i+t-1]);
      dp[i][i+t]=s;
    }
  }
  
  cout << dp[0][n] << endl;
  
  return 0;
}