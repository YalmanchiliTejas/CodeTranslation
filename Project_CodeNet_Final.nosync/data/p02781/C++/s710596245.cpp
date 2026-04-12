#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

int main() {
  string S; cin>>S;
  int N=S.size();
  int K; cin>>K;
  ll dp[101][2][5];
  rep(i, 101) rep(j, 2) rep(k, 5) dp[i][j][k]=0;
  dp[0][0][0]=1;  
  rep(i, N) {
    int D=S[i]-'0';
    rep(smaller, 2) {
      rep(k, K+1) {
        for (int d=0; d<=(smaller ? 9 : D); d++) {
          if (d!=0) dp[i+1][smaller||(d<D)][k+1]+=dp[i][smaller][k];
          else dp[i+1][smaller||(d<D)][k]+=dp[i][smaller][k];
        }
      }
    }
  }
  cout<<dp[N][0][K]+dp[N][1][K]<<endl;
}