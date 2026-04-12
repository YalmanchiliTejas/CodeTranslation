#include <bits/stdc++.h> // {{{

#define ARG5(a, b, c, d, NAME, ...) NAME
#define REP(...) ARG5(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)
#define REP1(a) REP2(i, a)
#define REP2(i, a) REP3(i, 0, a)
#define REP3(i, a, b) REP4(i, a, b, 1)
#define REP4(i, a, b, s) for (int i = (a); i < (int)(b); i += (s))
#define REPR(...) ARG5(__VA_ARGS__, REPR4, REPR3, REPR2, REPR1)(__VA_ARGS__)
#define REPR1(a) REPR2(i, a)
#define REPR2(i, a) REPR3(i, 0, a)
#define REPR3(i, a, b) REPR4(i, a, b, 1)
#define REPR4(i, a, b, s) for (int i = (b)-1; i >= (int)(a); i -= (s))
#define ALL(c) (c).begin(), (c).end()
#define DUMP(x) (std::cerr << #x << ':' << ' ' << x << '\n')
#define TMPL_T template <typename T>
#define TMPL_TU template <typename T, typename U>
#define mut auto
#define let const auto

using Int = long long;
// clang-format off
namespace extio {
std::string delimiter=" ",pdelimiter=" ";
std::string bracket_b="",bracket_e="";
void chdelim(const std::string&s){delimiter=s;}
void chpdelim(const std::string&s){pdelimiter=s;}
void chbracket(const std::string&b,const std::string&e){bracket_b=b,bracket_e=e;}
TMPL_T  void pcont(std::ostream&os,const T&x){int c=0;for(const auto&a:x){if(c++)os<<delimiter;os<<a;}}
TMPL_TU void ppair(std::ostream&os,const std::pair<T,U>&p){os<<bracket_b<<p.first<<pdelimiter<<p.second<<bracket_e;}
}
namespace std {
TMPL_T ostream& operator<<(ostream&os,const vector<T>&x){extio::pcont(os,x);return os;}
TMPL_T ostream& operator<<(ostream&os,const set<T>&x){extio::pcont(os,x);return os;}
TMPL_T ostream& operator<<(ostream&os,const multiset<T>&x){extio::pcont(os,x);return os;}
TMPL_T ostream& operator<<(ostream&os,const deque<T>&x){extio::pcont(os,x);return os;}
TMPL_TU ostream& operator<<(ostream&os,const map<T,U>&x){extio::pcont(os,x);return os;}
TMPL_TU ostream& operator<<(ostream&os,const pair<T,U>&x){extio::ppair(os,x);return os;}
TMPL_T istream& operator>>(istream&is,tuple<int&,vector<T>&>x)
{int N=get<0>(x);vector<T>&v=get<1>(x);v.clear();v.reserve(N);REP(i,N){T a;is>>a;v.emplace_back(a);}return is;}
TMPL_T istream& operator>>(istream&is,tuple<vector<T>&,int&>x){return is>>tie(get<1>(x),get<0>(x));}
TMPL_T istream& operator>>(istream&is,tuple<int&,T*>x){int N=get<0>(x);T*v=get<1>(x);REP(i,N){is>>v[i];}return is;}
TMPL_T istream& operator>>(istream&is,tuple<T*,int&>x){return is>>tie(get<1>(x),get<0>(x));}
}
TMPL_TU inline bool chmax(T&x,U a){return x<a&&(x=a,1);}
TMPL_TU inline bool chmin(T&x,U a){return a<x&&(x=a,1);}

inline int in(){int x;std::cin>>x;return x;}

// clang-format on
// }}}
//{{{ orliv::graph::Graph
#ifndef INCLUDE_GRAPH_HPP
#define INCLUDE_GRAPH_HPP
#include <limits>
#include <vector>
namespace orliv {
namespace graph {
struct Edge {
  using weight_type = long double;
  static constexpr weight_type INF = std::numeric_limits<weight_type>::max() - 100;

  int from, to;
  weight_type w;
  Edge(int from, int to, weight_type w = 1) : from(from), to(to), w(w) {}
  bool operator<(const Edge& rhs) const {
    if (w != rhs.w) return w > rhs.w;
    if (from != rhs.from) return from < rhs.from;
    return to < rhs.to;
  }
};

using Weight = Edge::weight_type;
using Edges = std::vector<Edge>;
using Weights = std::vector<Weight>;
using Path = std::vector<int>;
using Nodes = std::vector<int>;
}
using Graph = std::vector<graph::Edges>;
}
#endif
//}}}
//{{{ dijkstra.cc
#ifndef INCLUDE_GRAPH_HPP
#include "graph.hpp"
#endif
#include <algorithm>
#include <limits>
#include <queue>
namespace orliv {
namespace graph {
namespace shortest_path {
namespace util {
Path buildPath(int t, std::vector<int>& prev) {
  Path path;
  for (int u = t; u >= 0; u = prev[u]) {
    path.emplace_back(u);
  }
  std::reverse(path.begin(), path.end());
  return std::move(path);
}
}
Weights dijkstra(const Graph& g, int s, std::vector<int>& prev) {
  const int V = g.size();
  auto inf = Edge::INF;
  Weights dist(V, inf);
  prev.assign(V, -1);

  dist[s] = 0;
  std::priority_queue<Edge> pq;
  for (pq.emplace(-2, s, 0); !pq.empty();) {
    auto e = pq.top();
    pq.pop();
    if (prev[e.to] != -1) continue;
    prev[e.to] = e.from;
    for (const auto& f : g[e.to]) {
      if (dist[f.to] <= e.w + f.w) continue;
      pq.emplace(f.from, f.to, dist[f.to] = e.w + f.w);
    }
  }
  return std::move(dist);
}
Weights dijkstra(const Graph& g, int s) {
  std::vector<int> prev;
  return std::move(dijkstra(g, s, prev));
}
std::pair<Weight, Path> dijkstra(const Graph& g, int s, int t) {
  std::vector<int> prev;
  auto ws = dijkstra(g, s, prev);
  auto path = util::buildPath(t, prev);
  return std::move(std::make_pair(ws[t], std::move(path)));
}
}
}
}
//}}}

using namespace std;

using Real = double;
using P = std::complex<Real>;
struct L : vector<P> {
  L(const P& a, const P& b) { push_back(a), push_back(b); }
};

const Real EPS = 1e-8;
Real cross(const P& a, const P& b) {
  return imag(conj(a) * b);
}
Real dot(const P& a, const P& b) {
  return real(conj(a) * b);
}
int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) return +1;
  if (cross(b, c) < 0) return -1;
  if (dot(b, c) < 0) return +2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}
bool intersect(const L& a, const L& b) {
  return ccw(a[0], a[1], b[0]) * ccw(a[0], a[1], b[1]) <= 0 &&
         ccw(b[0], b[1], a[0]) * ccw(b[0], b[1], a[1]) <= 0;
}
bool intersectP(const L& s, const P& p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}
P projection(const L& l, const P& p) {
  Real t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}
Real distanceP(const L& s, const P& p) {
  const P r = projection(s, p);
  if (intersectP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
Real distance(const L& s, const L& t) {
  if (intersect(s, t)) return 0;
  return min({distanceP(s, t[0]), distanceP(s, t[1]), distanceP(t, s[0]), distanceP(t, s[1])});
}

struct Star {
  std::vector<P> ps;
  Star(Real x, Real y, Real a, Real r) {
    P base(x, y);
    P p = std::polar(r, (a + 90) / 180.0 * M_PI);
    P rot = std::polar(1.0, 0.4 * M_PI);
    REP(5) {
      ps.emplace_back(p + base);
      p *= rot;
    }
  }
  Real dist(const Star& other) const {
    Real d = 1e9;
    REP(i, 5) REP(j, 5) {
      int ni = (i + 2) % 5;
      int nj = (j + 2) % 5;
      chmin(d, ::distance(L(ps[i], ps[ni]), L(other.ps[j], other.ps[nj])));
    }
    return d;
  }
};

signed main() {
  int N, M, L;
  while (N = in(), M = in(), L = in(), N || M || L) {
    orliv::Graph g(N);
    vector<Star> stars;
    REP(i, N) {
      Real x = in(), y = in(), a = in(), r = in();
      stars.emplace_back(x, y, a, r);
    }
    REP(i, N) REP(j, N) {
      if (i == j) continue;
      auto d = stars[i].dist(stars[j]);
      g[i].emplace_back(i, j, d);
    }
    printf("%.20Lf\n", orliv::graph::shortest_path::dijkstra(g, M - 1, L - 1).first);
  }
  return 0;
}