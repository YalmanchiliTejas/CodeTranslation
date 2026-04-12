#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int dp[101][4][2];

int main(){
  string s; cin>>s;
  int K; cin>>K;
  int n = s.size();

  dp[0][0][1]=1;
  
  rep(i, n)rep(j, K+1)rep(k, 2)rep(a, 10){
    int x = s[i]-'0';
    int ni = i+1;
    int nj = j;
    int nk=k;
    // もし着目中の数値が0でなければ0でない数値のカウントを増やす。
    if(a)nj++;
    // 0の個数が4以上だと題意から除外可能なので除外する。
    if(nj>3)continue;
    // 今の所n丁度で着目中の数値と着目中の桁が一致してたら今の所n丁度継続、そうでなければn未満確定。着目数値の方が着目桁よりもデカければn超過確定なので飛ばす。
    if(k){
      if(a>x)continue;
      if(a<x)nk=0;
    }
    // k==0ならn未満確定なので何もしない、そのままnk==0で遷移する
    dp[ni][nj][nk] += dp[i][j][k];
  }
  cout<<dp[n][K][0]+dp[n][K][1]<<endl;

  return 0;

  rep(i, n+1)rep(j, K){
    rep(k, 2)cout<<dp[i][j][k]<<' ';
    cout<<endl;
  }

  return 0;
}

