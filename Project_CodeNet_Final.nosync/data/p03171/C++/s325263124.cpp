#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y){
  if(x>y) return x;
  return y;
}
int min(int x, int y){
  if(x<y) return x;
  return y;
}

int n;
long long a[3010];
long long dp[3010][3010];
int main() {
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
    dp[i][i]=0;
  }
  for(int l=1;l<=n;l++){
    for(int i=0;i<=n-l;i++){
      if((n-l)%2==0) dp[i][i+l]=max(dp[i][i+l-1]+a[i+l-1],dp[i+1][i+l]+a[i]);
      if((n-l)%2==1) dp[i][i+l]=min(dp[i][i+l-1]-a[i+l-1],dp[i+1][i+l]-a[i]);
    }
  }
  cout << dp[0][n] << endl;
}