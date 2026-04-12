#define MOD_TYPE 1

#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using multiInt = boost::multiprecision::cpp_int;
using lld = boost::multiprecision::cpp_dec_float_100;
*/
/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
*/
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
//constexpr ll MOD = 1;
constexpr int INF = (int)1e9;
constexpr ll LINF = (ll)4e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-11;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define REPI(i, m, n) for (int i = m; i < (int)(n); ++i)
#define repi(i, n) REPI(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

inline void init_main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
inline ll CEIL(ll a, ll b)
{
  return (a + b - 1) / b;
}
template <typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val)
{
  fill((T *)array, (T *)(array + N), val);
}
#pragma endregion

#pragma region kruskal
template <typename T>
struct kruskal
{
  vector<int> par, rank_;
  int V;
  kruskal(int V_) : V(V_)
  {
    par.resize(V);
    iota(begin(par), end(par), 0);
    rank_.assign(V, 0);
  };

  int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }

  bool same(int x, int y) { return root(x) == root(y); }

  void unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (rank_[x] < rank_[y])
    {
      par[x] = y;
    }
    else
    {
      par[y] = x;
      if (rank_[x] == rank_[y])
        rank_[x]++;
    }
  }

  struct edge
  {
    int u, v;
    T cost;
  };

  vector<edge> E;

  void add_E(int s, int t, T w)
  {
    E.push_back({s, t, w});
  }

  T calc()
  {
    sort(E.begin(), E.end(), [](edge &e1, edge &e2) { return e1.cost < e2.cost; });
    T res = 0;
    for (auto e : E)
    {
      if (!same(e.u, e.v))
      {
        unite(e.u, e.v);
        res += e.cost;
      }
    }
    return res;
  }
};
#pragma endregion

int main()
{
  init_main();

  int n;
  cin >> n;
  vector<tuple<ll, ll, int>> v(n);
  rep(i, n)
  {
    ll x, y;
    cin >> x >> y;
    v[i] = MT(x, y, i);
  }
  kruskal<ll> ks(n);
  sort(all(v));
  rep(i, n - 1)
  {
    ll x1 = get<0>(v[i]), y1 = get<1>(v[i]);
    ll x2 = get<0>(v[i + 1]), y2 = get<1>(v[i + 1]);
    ll cost = min(abs(x1 - x2), abs(y1 - y2));
    ks.add_E(get<2>(v[i]), get<2>(v[i + 1]), cost);
  }
  rep(i, n) swap(get<0>(v[i]), get<1>(v[i]));
  sort(all(v));
  rep(i, n - 1)
  {
    ll x1 = get<0>(v[i]), y1 = get<1>(v[i]);
    ll x2 = get<0>(v[i + 1]), y2 = get<1>(v[i + 1]);
    ll cost = min(abs(x1 - x2), abs(y1 - y2));
    ks.add_E(get<2>(v[i]), get<2>(v[i + 1]), cost);
  }
  cout << ks.calc() << endl;
  return 0;
}