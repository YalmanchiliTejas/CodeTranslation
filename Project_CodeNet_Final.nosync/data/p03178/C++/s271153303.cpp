#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
/* テンプレートここまで */
const int MOD = 1e9 + 7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  string K;  int D;
  cin >> K >> D;

  int L = K.size();
  
  vector<vector<vector<ll>>> dp(L+1, vector<vector<ll>>(D,vector<ll>(2, 0)));
  //dp[i][j][k] :  
  // 左からi桁目まで見て
  //桁和%D = j
  //k = 0: K未満が確定 1:o.w.
  dp[0][0][1]= 1;

  REP(i, L) REP(j, D) {
    REP(k, 10){
      (dp[i+1][(j+k)%D][0] += dp[i][j][0] ) %= MOD;
    }

    int d = K[i] - '0';
    REP(k, d){
      (dp[i+1][(j+k)%D][0] += dp[i][j][1]) %= MOD;
    }
    (dp[i+1][(j+d)%D][1] += dp[i][j][1] ) %= MOD;
  }

  // REP(i, L+1) REP(j, D) REP(k, 2){
  //   if(dp[i][j][k] == 0) continue;
  //   DUMP(i); DUMP(j); DUMP(k);
  //   DUMP(dp[i][j][k]);
  // } 

  //0を除くことに注意
  (dp[L][0][0] = dp[L][0][0] + MOD - 1) %= MOD;

  cout << (dp[L][0][0] + dp[L][0][1]) % MOD << endl;
}
