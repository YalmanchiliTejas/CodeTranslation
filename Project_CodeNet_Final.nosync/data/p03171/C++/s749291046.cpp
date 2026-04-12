#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  int n,k;
  cin>>n;
  if(n==1) {int x; cin>>x; cout<<x<<endl;}
  else if (n==2) {
  	int x, y; 
    cin>>x>>y;
   	cout<<max(x,y)-min(x,y)<<endl;
  }
  else {
    ll dp[n][n]={0};
    int a[n];
    ll sum = 0;
    for(int j=0,i=0;j<n;j++,i++) {cin>>a[i]; dp[i][j] = a[i]; sum+=dp[i][j];} 
    for(int i=1,j=0;i<n;j++,i++) dp[j][i] = max(dp[j+1][i], dp[j][i-1]); 

    for(int i=n-3;i>=0;i--) {
      for(int k=i,j=n-1;k>=0;j--,k--) {
        dp[k][j] = max(a[k]+ min(dp[k+2][j], dp[k+1][j-1]), a[j]+min(dp[k+1][j-1],dp[k][j-2]));
      }
    }
    
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    
    ll x = dp[0][n-1];
    ll y = sum - x;
    cout<<x-y<<endl;    
  }
}