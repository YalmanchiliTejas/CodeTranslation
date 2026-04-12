#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 998244353;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint N, S;
  cin >> N >> S;
  vector<lint> A(N);
  REP(i, N) cin >> A[i];
  vector<vector<lint>> dp(N+1, vector<lint>(S+1));
  dp[0][0] = 1;
  lint tmp = 0;
  REP(i, N) {
    dp[i+1][0] = dp[i][0] + 1;
    FOR(j, 1, S+1) {
      dp[i+1][j] = dp[i][j];
      if(j == S) dp[i+1][S] = (dp[i+1][S] + tmp) % MOD;
      if(j - A[i] >= 0) {
        dp[i+1][j] = (dp[i+1][j] + dp[i][j-A[i]]) % MOD;
        if(j == S) tmp = (tmp + dp[i][j-A[i]]) % MOD;
      }
    }
    //cout << dp[i+1][S] << endl;
  }
  cout << dp[N][S] << endl;
}