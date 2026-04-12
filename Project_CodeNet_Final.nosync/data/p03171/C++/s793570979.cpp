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
  int N;  cin >> N;
  vector<int> a(N); REP(i, N) cin >> a[i];

  //dp[l][r] : dequeの中身が a_l, a_{l+1}, ..., a_r の状態で
  //ゲーム開始した場合のX-Yの値 (0 <= l <= r <= N-1)
  //GOAL: dp[0][N-1]
  vector<vector<ll>> dp(N, vector<ll>(N, 0));
  REP(i, N){
    dp[i][i] = N%2 ? a[i] : -a[i];
  }

  FOR(i, 1, N){
    // r-l = i, すなわち要素数がi+1個の場合について考える
    REP(l, N-i){
      int r = l + i;
      dp[l][r] = (N-(i+1))%2 == 0 ? max(a[r]+dp[l][r-1], a[l]+dp[l+1][r]) 
                          : min(dp[l][r-1] - a[r], dp[l+1][r]-a[l]);
    }
  }
  cout << dp[0][N-1] << endl;
}
