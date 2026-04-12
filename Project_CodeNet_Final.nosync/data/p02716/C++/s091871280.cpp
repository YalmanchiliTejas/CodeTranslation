#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const ll INF = 1e18;

//i個までみてxをjこ入れたときのmax
ll dp[200005][4];

int main(void){
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n)cin >> a[i];
  //oxoxoxoxoの並びの中にxを入れる
  //入れる必要のあるxの個数
  //偶数->1
  //奇数->2
  ll k = 1 + n%2;
  REP(i, n+1) REP(j, k+1) dp[i][j] = -INF;
  dp[0][0] = 0;
  REP(i, n) REP(j, k+1){
    //xを入れる->a[i]をスキップする場合
    chmax(dp[i+1][j+1], dp[i][j]);
    ll now = dp[i][j];
    //xを1個入れるとoの位置が1つずれる
    //0 -> そのまま
    //1 -> 1つずれる
    //2 -> もう1つずれてもとに戻る
    if((i+j)%2 == 0) now += a[i];
    chmax(dp[i+1][j], now);
  }
  cout << dp[n][k] << endl;
  return 0;
}