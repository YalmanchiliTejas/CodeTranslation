#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
const int MOD = 1000000007;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  string k; cin >> k;
  int sz = k.size();
  int d; cin >> d;
  // true...tight
  vector<vector<vector<long long>>> dp(sz+1, vector<vector<long long>>(d, vector<long long>(2, 0)));
  dp[0][0][true] = 1;
  REP(i, sz) REP(j, d) {
    REP(l, k[i]-'0') (dp[i+1][(j+l)%d][false] += (dp[i][j][true] + dp[i][j][false]) % MOD) %= MOD;
    (dp[i+1][(j+(k[i]-'0'))%d][true] += dp[i][j][true]) %= MOD;
    FOR(l, k[i]-'0', 10) (dp[i+1][(j+l)%d][false] += dp[i][j][false]) %= MOD;
  }
  cout << (dp[sz][0][true] + dp[sz][0][false] - 1 + MOD) % MOD << '\n';
  return 0;
}
