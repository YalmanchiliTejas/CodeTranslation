#include <iostream>
using namespace std;

int main() {
  string s; cin>>s; int n=s.size();
  int t[n]; for(int i=0;i<n;i++) t[i]=s[i]-'0';
  int k; cin>>k;
  
  int dp[n+1][k+1][2]; fill(dp[0][0], dp[n+1][0], 0); dp[0][0][1] = 1;
  for(int i=0;i<n;i++) {
    for(int j=0;j<=k;j++) {
      for(int m=0;m<2;m++) {
        int C = m?t[i]-1:9;
        for(int c=0;c<=C;c++) {
          //cout<<"("<<c<<": "<<i<<" "<<j<<" "<<m<<") "<<i+1<<" "<<j+(c!=0)<<" "<<0<<" "<<dp[i][j][m]<<endl;
          if (j+(c!=0) <= k) dp[i+1][j+(c!=0)][0] += dp[i][j][m];
        }
        if (m&&(j+(t[i]!=0) <= k)) dp[i+1][j+(t[i]!=0)][m] = dp[i][j][m];
      }
    }
  }
  
  /*
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=k;j++) {
      cout<<dp[i][j][0]<<" ";
    } cout<<endl;
  } cout<<endl;
  
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=k;j++) {
      cout<<dp[i][j][1]<<" ";
    } cout<<endl;
  } cout<<endl;*/
  
  cout<<dp[n][k][0]+dp[n][k][1]<<endl;
}