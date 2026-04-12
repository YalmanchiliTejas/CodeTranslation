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

// dp[i][j]i桁目まで見た時に、0でない数値の個数がj個
// dp[i][j]:i桁目まで見ている時の数値の個数、j=0は今の所nと同値、j=1はn未満が確定
ll dp[101][2][4];

int main(){
  string s;cin>>s;
  int k;cin>>k;

  dp[0][0][0]=1;
  rep(i, s.size()){
    int c = s[i]-'0';
    rep(j, 10)rep(kk, 4){
      // kは非0の個数を表す、前のkの値をひとまずそのまま使い、もしjが0よりも大きければ非0が増えるのでインクリメントする。そしてk<=3なのでkが3を超えたら無視する。
      int nk=kk;
      if(j>0) nk++;
      if(nk>3)continue;

      if(j<c){
        // 今見ている桁の数値がNの同じ桁よりも小さいなら、その時点でN未満が確定する。なので、N一致とN未満確定の2つの個数を同時に加算する

        dp[i+1][1][nk] += dp[i][0][kk]+dp[i][1][kk];
        // cout<<dp[i][0][kk]<<' '<<dp[i][1][kk]<<endl;
      }else if(j==c){
        // 今見ている桁の数値がNと一致しているなら、前の桁の`今の所Nと一致している数値の個数`をそのまま加算する
        dp[i+1][0][nk] += dp[i][0][kk];
        // N未満が確定済みなら今見ている桁がNと一致していても問題ないのでN未満確定済みはそのまま加算する。
        dp[i+1][1][nk] += dp[i][1][kk];
      }else{
        // Nと一致している状態で、今見ている桁がNよりも大きいと、Nを超過するため、N未満確定の数値の個数のみ加算する
        dp[i+1][1][nk] += dp[i][1][kk];
      }
    }
    // rep(k,4)cout<<dp[i+1][0][k]<<' '<<dp[i+1][1][k]<<endl;
    // cout<<endl;
  }

  ll result = dp[s.size()][0][k] + dp[s.size()][1][k];
  cout<<result<<endl;

  return 0;
}
