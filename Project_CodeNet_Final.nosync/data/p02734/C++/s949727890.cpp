#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
/* const int MOD = 1000000007; */
const int MOD = 998244353;
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { 
  INIT(){cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;


signed main() {
  int N, S;
  cin >> N >> S;

  vector<int> A(N);
  REP(i, N) cin >> A[i];

  int dp[N+1][S+1][3];
  REP(i, N+1) REP(j, S+1) REP(k, 3) dp[i][j][k] = 0;
  dp[0][0][0] = 1;

  REP(i, N) REP(j, S+1){
    (dp[i+1][j][0] += dp[i][j][0]) %= MOD;
    (dp[i+1][j][1] += dp[i][j][0]+dp[i][j][1]) %= MOD;
    (dp[i+1][j][2] += dp[i][j][0]+dp[i][j][1]+dp[i][j][2]) %= MOD;
    if(j+A[i] <= S){
      (dp[i+1][j+A[i]][1] += dp[i][j][0]+dp[i][j][1]) %= MOD;
      (dp[i+1][j+A[i]][2] += dp[i][j][0]+dp[i][j][1]) %= MOD;
    }
  }

  cout << dp[N][S][2] << "\n";

  return 0;
}