// copied from https://atcoder.jp/contests/abc154/submissions/10014975
#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int dp[101][4][2];
// dp[i][j][k]
// i個までの桁を見ている時
// j個の非ゼロを使い
// k:0なら今の所Nと一致
// k:1ならすでにN以下が確定している

int main(){
  string s;cin>>s;
  int n=s.size();
  int K;cin>>K;
  dp[0][0][0]=1;
  rep(i,n)rep(j, 4)rep(k, 2){
    int nd = s[i]-'0';
    rep(d, 10){
      int ni = i+1, nj=j, nk=k;
      // 非ゼロなら次の遷移先のjの値を増やす
      if(d != 0) nj++;
      // 今の時点で使用済み非ゼロがK個よりも多ければ遷移しない
      if(nj > K )continue;
      // k==0:今の所nと一致している時
      if(k==0){
        // ループ中の桁がnの今着目している桁よりも大きければ、Nより大きくなるのは確定なのでノー遷移
        if(d>nd)continue;
        // ループ中の桁がnの今着目している桁よりも小さいなら、Nより小さくなるのは確定なのでkの値を1にして遷移させる
        if(d<nd)nk=1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int result = dp[n][K][0] + dp[n][K][1];
  cout<<result;

  return 0;
}
