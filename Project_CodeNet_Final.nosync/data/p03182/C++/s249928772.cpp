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
const int mod = 1000000007;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
ll modpow(ll a, int b, int _mod) { return b ? modpow(a * a % _mod, b / 2, _mod) * (b % 2 ? a : 1) % _mod : 1; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<typename T >inline istream& operator >> (istream& is, vector<T>& v) { rep(j, sz(v)) is >> v[j]; return is; }
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

template<typename T, typename T2>
struct LazySegmentTree {
private:
  int n;
  vector<T> node, lazy;
  using F = function<T(T, T)>;
  using G = function<T(T, T2)>;
  using H = function<T2(T2, T2)>;
  using P = function<T2(T2, int)>;
  F f; G g; H h; P p;
  T d1; T2 d0; // 単位元

public:
  LazySegmentTree(int _n, T _d1, T2 _d0,
    F _f, G _g, H _h, P _p = [](T2 a, int b) { return a; })
    : d1(_d1), d0(_d0), f(_f), g(_g), h(_h), p(_p) {
      n = 1;
      while (n < _n) n *= 2;
      node.resize(2*n-1, d1);
      lazy.resize(2*n-1, d0);

      for (int i = n - 2; i >= 0; --i) node[i] = f(node[i*2+1], node[i*2+2]);
  }

  void eval(int k, int l, int r) {
    if(lazy[k] == d0) return;

    if (r - l > 1) {
      lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
      lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
    }
    node[k] = g(node[k], p(lazy[k], r - l));
    lazy[k] = d0;
  }

  void change(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      eval(k, l, r);
    } else {
      change(a, b, x, 2*k+1, l, (l+r)/2);
      change(a, b, x, 2*k+2, (l+r)/2, r);
      node[k] = f(node[2*k+1], node[2*k+2]);
    }
  }

  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(k, l, r);
    if (b <= l || r <= a) return d0;
    if (a <= l && r <= b) return node[k];
    T vl = query(a, b, 2*k+1, l, (l+r)/2);
    T vr = query(a, b, 2*k+2, (l+r)/2, r);
    return f(vl, vr);
  }
};

// https://ferin-tech.hatenablog.com/entry/2019/01/09/101410
// https://twishort.com/Vntnc
// https://kyopro-friends.hatenablog.com/entry/2019/01/12/231106

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<pii> > G(n);
  rep(i, m) {
    int l, r, a;
    cin >> l >> r >> a;
    l--; r--;
    G[r].eb(pii(l, a));
  }

  auto f = [](ll a, ll b) { return max(a, b); };
  auto h = [](ll a, ll b) { return a + b; };
  // r 文字目までを考え, r 文字目を 1 にしたときのスコアの max
  LazySegmentTree<ll, ll> dp(n + 2, 0LL, 0LL, f, h, h);
  rep(r, n) {
    // dp[r] = max dp[j], 0 ≤ j < r;
    ll now = 0;
    if (r) chmax(now, dp.query(0, r));
    dp.change(r, r + 1, now);

    // r 文字目を 1 にすることで得られるスコア
    // r が終端の区間のスコアを強制で足す
    for (pii p : G[r]) {
      int l = p.F, a = p.S;
      dp.change(l, r + 1, a); 
    }
    // rep(_, n) cout << dp.query(_, _ + 1) << " "; cout << endl;
  }
  cout << max(0LL, dp.query(0, n + 1)) << endl;

}
