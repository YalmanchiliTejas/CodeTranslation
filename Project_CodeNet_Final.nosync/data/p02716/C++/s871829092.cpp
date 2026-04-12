#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
const int inf = 1e9 + 7;
const ll INF = 1e18;
// int mod = 998244353;
int mod = 1000000007;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll pow(ll a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
ll modpow(ll a, ll b, ll _mod) { return b ? modpow(a * a % _mod, b / 2, _mod) * (b % 2 ? a : 1) % _mod : 1; }
template<class T> ostream& operator << (ostream& os, const vector<T>& vec) { rep(i, sz(vec)) { if (i) os << " "; os << vec[i]; } return os; }
template<class T, class U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<typename T> inline istream& operator >> (istream& is, vector<T>& v) { rep(j, sz(v)) is >> v[j]; return is; }
template<class T, class T2> inline void add(T &a, T2 b) { a += b; if (a >= mod) a -= mod; }


void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);

  int T;
  // cin >> T;
  T = 1;

  while (T--) {
    solve();
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  vector<vector<ll> > dp(n + 1, vector<ll>(3, -INF));
  rep(j, 3) {
    if (-1 / 2 - 1 + j == 0) {
      dp[0][j] = 0;
    }
  }
  ll ans = -INF;
  rep(j, 3) {
    int j2 = 0 / 2 - 1 + j;
    if (j2 == 0) {
      dp[1][j] = 0;
    } else if (j2 == 1) {
      dp[1][j] = a[0];
    }
    if (j2 == n / 2) chmax(ans, dp[1][j]);
  }
  rep3(i, 1, n) {
    rep3(i2, i - 4, i - 1) { // どこから遷移するか
      if (i2 < -1) continue;
      rep(j, 3) {
        int j2 = i / 2 - 1 + j;
        rep(k, 3) {
          int k2 = i2 / 2 - 1 + k;
          if (j2 == k2) chmax(dp[i + 1][j], dp[i2 + 1][k]);
          else if (k2 + 1 == j2) chmax(dp[i + 1][j], dp[i2 + 1][k] + a[i]);
        }
        if (j2 == n / 2) chmax(ans, dp[i + 1][j]);
      }
    }
  }
  cout << ans << endl;
  // rep(i, n + 1) cout << dp[i] << endl;
}
