#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k); i > (n); i--)
#define FORre(i, k, n) for(int i = (k); i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

const int INF = 1001001001;
const int mod = 1000000007;

int main(void){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
  FORe(len, 1, n){
    for(int i = 0; i + len <= n; i++){
      int j = i + len;
      if((n-len)%2 == 0){
        dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
      }else{
        dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
      }
    }
  }

  cout << dp[0][n] << endl;
  return 0;
}