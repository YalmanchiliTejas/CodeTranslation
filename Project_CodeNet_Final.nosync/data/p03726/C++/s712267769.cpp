#define ONLINE_JUDGE
// {{{ Includes
#ifndef ONLINE_JUDGE
#pragma clang diagnostic warning "-Wall"
#pragma clang diagnostic warning "-Wextra"
#pragma clang diagnostic warning "-Weverything"
#pragma clang diagnostic warning "-Wconversion"
#pragma clang diagnostic ignored "-Wvla"
#pragma clang diagnostic ignored "-Wvla-extension"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wmissing-prototypes"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wsign-compare"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wunused-const-variable"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wcomma"
#pragma clang diagnostic ignored "-Wfloat-equal" // it's fine
#pragma clang diagnostic ignored "-Wdouble-promotion" // also
#endif

#include <unordered_map>
#include <random>
#include <climits>
#include <array>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>
#include <cstring>
#include <limits>
#include <chrono>
#include <unistd.h>
using namespace std;
// }}}
// {{{ Utilities
#ifdef ONLINE_JUDGE
static bool debug = false;
#else
static bool debug = true;
#endif
#define db(x) #x << "=" << (x) << " "
#define dprintf debug && printf

#define All(x) x.begin(), x.end()
#define Loop(i, n) for (int i = 0; i < int(n); ++i)
template <typename T, typename Q, typename S>
bool Bounded(const T &x, const Q &a, const S &b) { return a <= x && x <= b; }

typedef long double Real;
const Real pi = 4*atan(Real(1.0));
const Real Inf = numeric_limits<Real>::infinity();
// https://github.com/JuliaLang/julia/blob/master/base/floatfuncs.jl
Real isapprox(Real x, Real y, Real rtol = sqrt(numeric_limits<Real>::epsilon()), Real atol = Real(0.0), bool nans = false) { return x == y || (nans && isnan(x) && isnan(y)) || (isfinite(x) && isfinite(y) && abs(x - y) <= atol + rtol*max(abs(x), abs(y))); }
typedef long long int ll;
typedef vector<Real> Vd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<bool> Vb;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

template <typename T> int sz(const T &x) { return (int)x.size(); }
template <typename T, typename Q> bool mem(const T &s, const Q &x) { return s.find(x) != s.end(); }
template <typename T> void push(vector<T>& c, const T& e) { c.push_back(e); }
template <typename T> void push(queue<T>& c, const T& e) { c.push(e); }
template <typename T> void push(set<T>& c, const T& e) { c.insert(e); }
template <typename T> T pop(vector<T>& v) { assert(!v.empty()); T u = v.back(); v.pop_back(); return u;}
template <typename T> T pop(queue<T>& v) { assert(!v.empty()); T u = v.back(); v.pop(); return u;}
template <typename T, typename... Args> auto emplace(vector<T>& c, Args&&... args) -> decltype(c.emplace_back(args...)) { c.emplace_back(args...); }
template <typename T, typename... Args> auto emplace(queue<T>& c, Args&&... args) -> decltype(c.emplace(args...)) { c.emplace(args...); }
template <typename T, typename... Args> auto emplace(set<T>& c, Args&&... args) -> decltype(c.emplace(args...)) { c.emplace(args...); }
template <typename T> void umin(T &x, const T &y) { x = min(x, y); }
template <typename T> void umax(T &x, const T &y) { x = max(x, y); }
template <typename T> int sign(const T &x) {
  return x == 0 ? 0 : x > 0 ? 1 : -1;
}
template <typename T> T square(const T &x) { return x * x; }
// }}}
// {{{ IO
template <typename S, typename T>
istream& operator>>(istream& in, pair<S, T>& p) { return in >> p.first >> p.second; }
template <typename T> T read() { T x; cin >> x; return x; }
template <typename T, typename I = typename T::iterator>
void read(T &cnt) { for (auto& x : cnt) cin >> x; }
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  return out << "{" << p.first << ", " << p.second << "}";
}
template <typename T> struct show_container {
  const T &container;
  show_container(const T &container_) : container(container_) {}
};
template <typename T>
ostream &operator<<(ostream &o, const show_container<T> &thing) {
  bool first = true;
  o << "{";
  for (const auto &x : thing.container) {
    if (!first)
      o << ", ";
    first = false;
    o << x;
  }
  o << "}";
  return o;
}
template <typename T> show_container<T> show(const T &container) {
  return show_container<T>(container);
}

#define dprintf debug && printf
struct dout_ { } dout;
#ifdef ONLINE_JUDGE
template <typename T> dout_ &operator<<(dout_ &out, const T &thing) { return out; }
dout_ &operator<<(dout_ &out, ostream &(*thing)(ostream &)) { return out; }
#else
template <typename T> dout_ &operator<<(dout_ &out, const T &thing) { if (debug) cerr << thing; return out; }
dout_ &operator<<(dout_ &out, ostream &(*thing)(ostream &)) { if (debug) cerr << thing; return out; }
#endif

struct outboth {
  ostream &a;
  ostream &b;
  outboth(ostream &a_, ostream &b_) : a(a_), b(b_) {}
};
template <typename T> outboth &operator<<(outboth &both, const T &thing) {
  both.a << thing;
  both.b << thing;
  return both;
}
outboth &operator<<(outboth &both, ostream &(*thing)(ostream &)) {
  both.a << thing;
  both.b << thing;
  return both;
}
// }}}
// {{{ Solver

#ifdef ONLINE_JUDGE
void solve(ostream& rout)
#else
void solve(outboth rout)
#endif
{

  int N; cin >> N; if (!cin) return;
  vector<Pii> edges(N-1); read(edges);
  vector<set<int>> adj(N);
  for (Pii& e : edges) {
    --e.first, --e.second;
    assert(Bounded(e.first, 0, N-1) && Bounded(e.second, 0, N-1));
    push(adj[e.first], e.second);
    push(adj[e.second], e.first);
  }
  dout << db(N) << show(edges) << endl;

  Vi parent(N, -1), depth(N, INT_MAX);
  Vb marked(N), finished(N);
  function<void(int, int)> dfs = [&](int u, int d) {
    assert(!marked[u]);
    depth[u] = d;
    marked[u] = true;
    for (int v : adj[u]) {
      if (marked[v]) continue;
      dfs(v, d+1);
      parent[v] = u;
    }
    finished[u] = true;
  };
  Loop(i, N) if (!marked[i]) dfs(i, 0);

  Vi ix(N); iota(All(ix), 0);
  sort(All(ix), [&](int i, int j) { return depth[i] > depth[j]; });
  Vb match(N);
  for (int u : ix) {
    for (int v : adj[u]) {
      if (!match[u] && !match[v]) {
        dout << db(u) << db(v) << endl;
        match[u] = match[v] = true;
      }
    }
  }
  bool win = std::count(All(match), true) < N;

  // queue<int> q;
  // Loop(i, N) if (sz(adj[i]) == 1) push(q, i);
  // // Mostly correct
  // Vb finished(N);
  // bool win = false;
  // while (!q.empty() && !win) {
  //   int i = pop(q);
  //   if (finished[i]) continue;
  //   if (sz(adj[i]) == 0) {
  //     win = true;
  //     break;
  //   }
  //   assert(sz(adj[i]) == 1);
  //   int j = *adj[i].begin();
  //   dout << db(i) << db(j) << endl;
  //   for (int k : adj[j]) {
  //     adj[k].erase(j);
  //     if (k != i) {
  //       if (sz(adj[k]) == 1) push(q, k);
  //       if (sz(adj[k]) == 0) win = true;
  //     }
  //     dout << db(k) << db(sz(adj[k])) << endl;
  //   }
  //   finished[i] = true;
  // }

  rout << (win ? "First" : "Second") << endl;
}

// }}}
// {{{ Main

int main() {
  // freopen("D.in", "r", stdin);
  // freopen("D.out", "w", stdout);
  std::ios::sync_with_stdio(false); cin.tie(nullptr);
  solve(cout);
  return 0;
}
// }}}

// clang-format off
// Local variables:
// compile-command: "make D && ./D"
// irony-additional-clang-options: ("-std=c++11")
// End:
