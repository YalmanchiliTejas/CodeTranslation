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
// dp[i][j][k]
// i個までの桁を見ている時
// j個の非ゼロを使い
// k:0なら今の所Nと一致
// k:1ならすでにN以下が確定している

int main(){
  string s;cin>>s;
  int k;cin>>k;
  int n=s.size();
  dp[0][0][0]=1;

  rep(i, n)rep(j, 4)rep(kk, 2){
    int c = s[i]-'0';
    rep(d, 10){
      int ni=i+1, nj=j, nk=kk;
      if(d!=0)nj++; // 非0が増えたのでインクリメント
      if(nj>3)continue; //配列に収まりきらないので無視

      if(kk==0){
        if(d>c)continue; // 着目中の数値がnの桁よりも大きければN超過確定なので無視
        if(d<c) nk=1; // 桁同士の比較がこれまでNと同じで、着目中の桁で初めて下回ったのでN以下確定。
      }

      dp[ni][nj][nk] += dp[i][j][kk];
    }
  }

//  cout<<dp[n][k][1]<<' '<<dp[n][k][0]<<endl;
  cout<<dp[n][k][1]+dp[n][k][0]<<endl;

  return 0;
}