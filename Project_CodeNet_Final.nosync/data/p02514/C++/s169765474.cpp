#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define FOREQ(i, s, n) for (ll i = (s); i <= (ll)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))


typedef ll Weight;
struct Edge {
  ll index;
  ll src;
  ll dest;
  Weight weight;
  Edge(ll index, ll src, ll dest, Weight weight) : index(index), src(src), dest(dest), weight(weight) {;}
  bool operator<(const Edge &rhs) const {
    if (weight != rhs.weight) { return weight > rhs.weight; }
    if (src != rhs.src) { return src < rhs.src; }
    return dest < rhs.dest;
  }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void PrintMatrix(const Matrix &matrix) {
  for (ll y = 0; y < (ll)matrix.size(); y++) {
    for (ll x = 0; x < (ll)matrix[y].size(); x++) {
      printf("%lld ", matrix[y][x]);
    }
    puts("");
  }
}

Weight augment(const Graph &g, Array &capacity, const vector<ll> &level, vector<bool> &finished, ll from, ll t, Weight cur) {
  if (from == t || cur == 0) { return cur; }
  if (finished[from]) { return 0; }
  for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
    ll to = it->dest;
    if (level[to] != level[from] + 1) { continue; }
    Weight f = augment(g, capacity, level, finished, to, t, min(cur, capacity[it->index]));
    if (f > 0) {
      capacity[it->index] -= f;
      capacity[it->index^1] += f;
      return f;
    }
  }
  finished[from] = true;
  return 0;
}

// index^1 is reverse edge
Weight MaxFlow(const Graph &g, ll e, ll s, ll t) {
  ll n = g.size();
  Array capacity(e);
  for (ll from = 0; from < n; from++) {
    for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
      capacity[it->index] += it->weight;
    }
  }
  ll ans = 0;
  while (true) {
    vector<ll> level(n, -1);
    level[s] = 0;
    queue<ll> que;
    que.push(s);
    for (ll d = n; !que.empty() && level[que.front()] < d; ) {
      ll from = que.front();
      que.pop();
      if (from == t) { d = level[from]; }
      for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
        ll to = it->dest;
        if (capacity[it->index] > 0 && level[to] == -1) {
          que.push(to);
          level[to] = level[from] + 1;
        }
      }
    }
    vector<bool> finished(n);
    bool end = true;
    while (true) {
      Weight f = augment(g, capacity, level, finished, s, t, 2000000000LL);
      if (f == 0) { break; }
      ans += f;
      end = false;
    }
    if (end) { break; }
  }
  return ans;
}

void AddEdge(Graph &g, ll &e, ll from, ll to, Weight capacity) {
  g[from].push_back(Edge(e++, from, to, capacity));
  g[to].push_back(Edge(e++, to, from, 0));
}

int main() {
  ll n, m;
  while (scanf("%lld %lld", &n, &m), n|m) {
    Graph g(n);
    ll total = 0;
    ll e = 0;
    REP(i, m) {
      ll from, to, cost;
      scanf("%lld %lld %lld", &from, &to, &cost);
      if (cost <= 0) { total += cost; continue; }
      AddEdge(g, e, from, to, cost);
      AddEdge(g, e, to, from, cost);
    }
    ll ans = 1LL << 60;
    REP(i, n) {
      if (i == 0) { continue; }
      ans = min(ans, MaxFlow(g, e, 0, i) + total);
    }
    printf("%lld\n", ans);
  }
}