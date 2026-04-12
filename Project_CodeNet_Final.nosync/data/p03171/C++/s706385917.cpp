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
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
const int mod = 1000000007;
ll modpow(ll a, int b) { return b ? modpow(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<class T> inline void add(T &a, int b) { a += b; if (a >= mod) a -= mod; }



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

ll dp[3003][3003];
int n;
vector<int> a;

ll dfs(int l, int r, int key) { // 数列の [l, r], どっちがとる
  if (dp[l][r] != -1) return dp[l][r];
  if (l == r) return dp[l][r] = (key == 0 ? a[l] : -a[l]);

  ll ret;
  ret = dfs(l + 1, r, key ^ 1) + (key == 0 ? a[l] : -a[l]);
  if (key == 0) {
    chmax(ret, dfs(l, r - 1, key ^ 1) + a[r]);
  } else {
    chmin(ret, dfs(l, r - 1, key ^ 1) - a[r]);
  }

  return dp[l][r] = ret;
}

void solve() {
  cin >> n;
  a.resize(n);
  rep(i, n) cin >> a[i];
  // 後退解析
  fill_n(*dp, 3003 * 3003, -1);
  cout << dfs(0, n - 1, 0) << endl;
  // rep(i, n) { rep(j, n) cout << dp[i][j] << " "; cout << endl; }
}
