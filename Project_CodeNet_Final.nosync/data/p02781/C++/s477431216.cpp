#include<bits/stdc++.h>
using namespace std;
int main(){
  string nn;
  cin >> nn;
  vector<int>n(nn.length());
  int i,smaller,j;
  for(i=0;i<nn.length();i++){
    n[i] = (int)(nn[i]-'0');
  }
  int k;
  cin >> k;
  // dp[i][smaller][j];
  vector<vector<vector<long> > >dp(nn.length()+1,vector<vector<long> >(2,vector<long>(5,0)));
  dp[0][0][0] = 1;
  for(i=0;i<nn.length();i++){
    for(smaller=0;smaller<=1;smaller++){
      for(j=0;j<=3;j++){
        if(smaller == 0){
          if(n[i]==0){
            dp[i+1][0][j] += dp[i][0][j];
          }else{
            dp[i+1][0][j+1] += dp[i][0][j];
            dp[i+1][1][j] += dp[i][0][j];
            dp[i+1][1][j+1] += dp[i][0][j] * (n[i]-1);
          }
        }else{
          dp[i+1][1][j] += dp[i][1][j];
          dp[i+1][1][j+1] += dp[i][1][j]*9;
        }
      }
    }
  }
  cout << dp[nn.length()][0][k] + dp[nn.length()][1][k] << endl;
}
