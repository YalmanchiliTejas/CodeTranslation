#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;cin >> s;
  int K;cin >> K;
  int n=s.size();
  ll dp[n+1][2][K+2];
  memset(dp,0,sizeof(dp));
  dp[0][0][0]=1;
  for(int i=0;i<n;i++){
    int p=s[i]-'0';
    for(int j=0;j<2;j++){
      for(int k=0;k<=K;k++){
        for(int l=0;l<=(j?9:p);l++){
          dp[i+1][j||(l<p)][k+(l!=0)]+=dp[i][j][k];
        }
      }
    }
  }
  cout << dp[n][0][K]+dp[n][1][K] << endl;
}