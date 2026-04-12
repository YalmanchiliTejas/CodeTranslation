#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
#define ll long long
using namespace std;

int main() {
  string N; cin>>N;
  int K; cin>>K;
  int n=N.size();
  ll dp[105][2][105]; //1th:桁(上からi個目), 2th:未満(0)or一致(1), 3th:0が何個入ってる？
  for (int i=0; i<=n; i++) {
    for (int j=0; j<2; j++) {
      for (int k=0; k<105; k++) {
        dp[i][j][k]=0;
      }
    }
  }
  dp[0][0][0]=1;
  for (int i=0; i<n; i++) {
    int D=N[i]-'0';
    for (int j=0; j<2; j++) {
      for (int k=0; k<101; k++) {
        for (int l=0; l<=(j ? 9 : D); l++) {
          if (l==0) dp[i+1][j||(l<D)][k+1]+=dp[i][j][k];
          else dp[i+1][j||(l<D)][k]+=dp[i][j][k];
        }
      }
    }
  }
  ll res=dp[n][0][n-K]+dp[n][1][n-K];
  cout<<res<<endl;
}