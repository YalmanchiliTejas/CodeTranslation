#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main(){
  string s;cin >> s;
  int n=s.size();
  int d;cin >> d;
  ll dp[n+1][2][d];
  memset(dp,0,sizeof(dp));
  dp[0][0][0]=1;
  for(int i=0;i<n;i++){
    int p=s[i]-'0';
    for(int j=0;j<2;j++){
      for(int k=0;k<d;k++){
        for(int l=0;l<=(j?9:p);l++){
          dp[i+1][j||(l<p)][(k+l)%d]+=dp[i][j][k];
          dp[i+1][j||(l<p)][(k+l)%d]%=mod;
        }
      }
    }
  }
  cout << (dp[n][0][0]+dp[n][1][0]-1+mod)%mod << endl;
}