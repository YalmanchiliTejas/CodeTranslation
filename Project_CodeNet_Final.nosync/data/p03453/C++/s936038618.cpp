#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define endl '\n'
const int inf = 1000000007;
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
template<typename T, typename U> T pow_(T a, U b) { return b ? pow_(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
ll modpow(ll a, ll b, ll _mod) { return b ? modpow(a * a % _mod, b / 2, _mod) * (b % 2 ? a : 1) % _mod : 1; }
template<class T, class U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<class T> ostream& operator << (ostream& os, const vector<T>& vec) { rep(i, sz(vec)) { if (i) os << " "; os << vec[i]; } return os; }
template<typename T> inline istream& operator >> (istream& is, vector<T>& v) { rep(j, sz(v)) is >> v[j]; return is; }
template<class T, class T2> inline void add(T &a, T2 b) { a += b; if (a >= mod) a -= mod; }


void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int T;
  T = 1;
  while (T--) solve();
}

// https://www.youtube.com/watch?v=br3ze-KC6WA&t=2639s
// http://kirika-comp.hatenablog.com/entry/2018/01/29/020648
void solve() {
  int n, m;
  cin >> n >> m;
  int s, t;
  cin >> s >> t;
  s--; t--;
  vector<vector<pil> > G(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    G[a].eb(b, c);
    G[b].eb(a, c);
  }

  auto dijkstra = [&](int s) {
    vector<pll> d(n, pli(INF, 0)); // 最短距離, その本数
    vector<int> vis(n);
    //頂点、最短距離、小さい順に
    priority_queue<pli, vector<pli>, greater<pli> > q;

    d[s] = pll(0, 1);
    q.push(pli(0, s));

    while (!q.empty()) {
      pli p = q.top();
      q.pop();
      int v = p.S;

      if (vis[v]) continue;
      vis[v] = 1;

      for (pil np : G[v]) {
        int nv;
        ll cost;
        tie(nv, cost) = np;

        pll tmp = pli(d[v].F + cost, d[v].S);
        if (d[nv].F != tmp.F) d[nv] = min(d[nv], tmp); // 最短距離の更新
        else d[nv] = pli(d[nv].F, (d[nv].S + d[v].S) % mod); // 最短距離の本数増やす
        q.push(pli(d[nv].F, nv));
      }
    }
    return d;
  };

  auto d1 = dijkstra(s), d2 = dijkstra(t);
  ll ans = d1[t].S * d1[t].S % mod;
  // cerr << ans << endl;

  rep(i, n) {
    if (d1[i].F + d2[i].F != d1[t].F) continue; // 最短経路じゃない
    // 両方から等距離, 頂点でぶつかる
    // d1 で, i から t に行く場合の数は d2[i]
    // d1, d2 の組み合わせで, ^2
    if (d1[i].F * 2 == d1[t].F) (ans += mod - modpow(d1[i].S * d2[i].S % mod, 2, mod)) %= mod;
    // 辺でぶつかる可能性
    if (d1[i].F * 2 < d1[t].F) {
      for (pil np : G[i]) {
        int nv; ll cost;
        tie(nv, cost) = np;
        if (d1[i].F + cost + d2[nv].F != d1[t].F) continue;
        if (d2[nv].F * 2 < d1[t].F) {
          // cerr << i << endl;
          (ans += mod - modpow(d1[i].S * d2[nv].S % mod, 2, mod)) %= mod;
        }
      }
    }
  }
  cout << ans << endl;
}
