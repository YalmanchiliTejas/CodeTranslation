#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rsort(v) sort(all(v)); reverse(all(v))

using namespace std;

using i32 = int;
using i64 = long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }
template<typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template<typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template<typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template<typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template<typename T> inline T power(T x, i64 n) { T r = 1; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }

template<int mod>
struct ModInt {
  int x;
  ModInt(): x(0) {}
  ModInt(i64 a) { x = a % mod; if (x < 0) x += mod; }
  ModInt &operator+=(ModInt that) { x = (x + that.x) % mod; return *this; }
  ModInt &operator-=(ModInt that) { x = (x + mod - that.x) % mod; return *this; }
  ModInt &operator*=(ModInt that) { x = (i64) x * that.x % mod; return *this; }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
  ModInt operator-() { return ModInt(-this->x); }
  friend ostream& operator<<(ostream &os, ModInt m) { return os << m.x; }
  ModInt inverse() {
    int a = x, b = mod, u = 1, v = 0;
    while (b) { int t = a / b; a -= t * b; u -= t * v; swap(a, b); swap(u, v); }
    return ModInt(u);
  }
  #define op(o, p) ModInt operator o(ModInt that) { return ModInt(*this) p that; }
    op(+, +=) op(-, -=) op(*, *=) op(/, /=)
  #undef op
  #define op(o) bool operator o(ModInt that) const { return x o that.x; }
    op(==) op(!=) op(<) op(<=) op(>) op(>=)
  #undef op
};

using mint = ModInt<1000000007>;

struct Edge { int to, cost; };
vector<vector<Edge>> edges;

pair<vi64, vector<mint>> dijkstra(int s, int n) {
  vi64 dist(n, 1e18);
  vector<mint> cnt(n, 0);
  dist[s] = 0;
  cnt[s] = 1;
  using P = pair<i64, int>;
  pqasc<P> pq;
  vector<bool> used(n);
  pq.push({0, s});
  while (!pq.empty()) {
    auto p = pq.top(); pq.pop();
    i64 d, v;
    tie(d, v) = p;
    if (used[v]) continue;
    used[v] = true;
    each(e, edges[v]) {
      if (used[e.to]) continue;
      if (dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        pq.push({dist[e.to], e.to});
        cnt[e.to] = cnt[v];
      } else if (dist[e.to] == dist[v] + e.cost) {
        cnt[e.to] += cnt[v];
      }
    }
  }
  return make_pair(dist, cnt);
}

void solve() {
  int N, M; cin >> N >> M;
  int S, T; cin >> S >> T;
  S--, T--;
  edges = vector<vector<Edge>>(N);
  rep(i, M) {
    int U, V, D; cin >> U >> V >> D;
    U--, V--;
    edges[U].push_back({V, D});
    edges[V].push_back({U, D});
  }
  auto dist_s = dijkstra(S, N);
  auto dist_t = dijkstra(T, N);
  auto ds = dist_s.first, dt = dist_t.first;
  auto cs = dist_s.second, ct = dist_t.second;

  i64 d = ds[T];
  mint ans = power((mint) cs[T], 2);
  rep(i, N) {
    if (ds[i] * 2 == d) {
      ans -= power((mint) cs[i], 2) * power((mint) ct[i], 2);
    }
  }
  rep(i, N) each(e, edges[i]) {
    if (ds[i] != d - dt[i] || ds[e.to] != d - dt[e.to]) {
      continue;
    }
    if (2 * ds[i] < d && 2 * ds[e.to] > d && ds[i] + e.cost == ds[e.to]) {
      ans -= power((mint) cs[i], 2) * power((mint) ct[e.to], 2);
    }
  }
  cout << ans << '\n';
}
