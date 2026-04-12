#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;


signed main() {
  string s;
  cin >> s;

  int K;
  cin >> K;

  int N = s.size();

  int dp[N+1][K+2][2];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;

  REP(i, N) REP(j, K+1){
    int d = s[i]-'0';

    dp[i+1][j][1] += dp[i][j][1];
    dp[i+1][j+1][1] += dp[i][j][1]*9;

    if(d != 0){
      dp[i+1][j][1]   += dp[i][j][0];
      dp[i+1][j+1][1] += dp[i][j][0]*(d-1);
      dp[i+1][j+1][0] += dp[i][j][0];
    }else{
      dp[i+1][j][0] += dp[i][j][0];
    }
  }

  cout << dp[N][K][0]+dp[N][K][1] << "\n";

  return 0;
}