#include <bits/stdc++.h>
#define int long long
#define uint unsigned int
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) ((int)(a).size())
#define PB(a) push_back(a)
#define EB(...) emplace_back(__VA_ARGS__)
#define MP(a, b) make_pair(a, b)
#define MT(...) make_tuple(__VA_ARGS__)
using namespace std;
using pii = pair<int, int>;
template <class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const int INF = 1LL << 30;
const double EPS = 1e-10;

string K;
int D;
int dp[10010][2][110];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> K >> D;
  int n = SZ(K);
  dp[0][0][0] = 1;
  REP(i, n) REP(j, 2) REP(k, D) if (dp[i][j][k]) {
    int lim = j ? 9 : K[i]-'0';
    for (int d = 0; d <= lim; d++) {
      (dp[i+1][j | (d < lim)][(k+d)%D] += dp[i][j][k]) %= MOD;
    }
  }
  cout << (dp[n][0][0] + dp[n][1][0] + MOD - 1) % MOD << endl;

  return 0;
}