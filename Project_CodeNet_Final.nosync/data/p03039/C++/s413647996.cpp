#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, S, E) for (int(X) = (S); (X) < (E); ++(X))
#define rrep(X, S, E) for (int(X) = (E)-1; (X) >= (S); --(X))
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
#define all(X) (X).begin(), (X).end()
#define sortDecending(X) sort(all(X), greater<ll>()) //降順
#define sortAscending(X) sort(all(X))                //昇順
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl
#define printDouble(x) cout << fixed << setprecision(13) << x << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef priority_queue<ll, vl> decendingQueue;              //降順
typedef priority_queue<ll, vl, greater<ll>> ascendingQueue; //昇順
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll INF = 9 * 1e18;
const ll MOD = 1e9 + 7;

long long gcd(long long m, long long n) {
  if (m < n)
    return gcd(n, m);
  if (n == 0)
    return m;
  return gcd(n, m % n);
}

long long lcm(long long m, long long n) {
  // m * nでlong型のオーバフローを発生させないため、先に割り算から行う
  return m * (n / gcd(m, n));
}

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint &operator+=(const mint a) {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a) {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
      fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i)
      ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n)
      return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

vector<long long> SieveOfEratosthenes(int max) {
  vector<long long> sieve;
  vector<long long> primes;

  for (int i = 1; i < max + 1; ++i) {
    sieve.push_back(i);
  }

  sieve[0] = 0;
  for (int i = 2; i < max + 1; ++i) {
    if (sieve[i - 1] != 0) {
      primes.push_back(sieve[i - 1]);
      for (int j = 2 * sieve[i - 1]; j < max + 1; j += sieve[i - 1]) {
        sieve[j - 1] = 0;
      }
    }
  }
  return primes;
}

class Combination {
private:
  vector<long long> fac_;
  vector<long long> finv_;
  vector<long long> inv_;
  long long prime_;

public:
  Combination(long long n, long long prime) {
    fac_ = vector<long long>(n + 1);
    finv_ = vector<long long>(n + 1);
    inv_ = vector<long long>(n + 1);
    prime_ = prime;

    fac_[0] = fac_[1] = 1;
    finv_[0] = finv_[1] = 1;
    inv_[1] = 1;
    for (long long i = 2; i <= n; i++) {
      fac_[i] = fac_[i - 1] * i % prime_;
      inv_[i] = prime_ - inv_[prime_ % i] * (prime_ / i) % prime_;
      finv_[i] = finv_[i - 1] * inv_[i] % prime_;
    }
  }

  // nCk
  long long getCombination(long long n, long long k) {
    if (n < k)
      return 0;
    if (n < 0 || k < 0)
      return 0;

    return fac_[n] * (finv_[k] * finv_[n - k] % prime_) % prime_;
  }
};

class UnionFindTree {
private:
  vector<int> par;
  vector<int> rnk;
  vector<int> siz;

public:
  UnionFindTree(int n) {
    par.assign(n, -1);
    rnk.assign(n, -1);
    siz.assign(n, -1);

    for (int i = 0; i < n; ++i) {
      par[i] = i;
      rnk[i] = 0;
      siz[i] = 1;
    }
  }

  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

  bool same(int x, int y) { return find(x) == find(y); }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rnk[x] < rnk[y]) {
      par[x] = y;
      siz[y] += siz[x];
    } else {
      par[y] = x;
      siz[x] += siz[y];
      if (rnk[x] == rnk[y])
        ++rnk[x];
    }
  }

  int size(int x) {
    x = find(x);
    return siz[x];
  }
};

class Edge {
public:
  ll from;
  ll to;
  ll cost;

  Edge() {}
  Edge(ll from, ll to, ll cost) {
    this->from = from;
    this->to = to;
    this->cost = cost;
  }

  bool operator<(const Edge &edge) const {
    return cost < edge.cost; //昇順
  }
};

class Graph {
public:
  ll nodes; // ノード数
  vector<Edge> edges;

  Graph() {}
  Graph(ll nodes) { this->nodes = nodes; }
  void addEdge(ll from, ll to, ll cost) {
    this->edges.push_back(Edge(from, to, cost));
  }
};

// クラスカル法
// 連結グラフの最小全域木を求める
class Kruskal {
private:
  Graph graph;
  vector<Edge> MinimumSpanningTree;
  ll minimumCost;
  void searchMinimumSpanningTree() {
    UnionFindTree uf(graph.nodes);
    sort(all(graph.edges));
    itrep(edge, graph.edges) {
      if (!uf.same(edge->from, edge->to)) {
        uf.unite(edge->from, edge->to);
        MinimumSpanningTree.push_back(*edge);
      }
    }
  }

public:
  Kruskal(Graph graph) { this->graph = graph; }
  ll getMinimumSpanningTreeCost() {
    searchMinimumSpanningTree();
    ll cost = 0;
    itrep(it, MinimumSpanningTree) { cost += it->cost; }
    return cost;
  }
};

// ダイクストラ法 O((E+V)logV)
// 最小経路問題を解くためのアルゴリズム。辺の重みに負数を含む場合は利用不可
// 有向グラフ(無向グラフ)の場合はコメントアウト箇所をコメントイン
class Dijkstra {
private:
  Graph graph;
  map<ll, vector<Edge>> fromPaths;
  vl distances;
  vl srcs;

public:
  Dijkstra(Graph graph) {
    this->graph = graph;
    itrep(edge, graph.edges) {
      fromPaths[edge->from].push_back(*edge);
      // fromPaths[edge->to].push_back(Edge(edge->to, edge->from, edge->cost));
    }
  }
  void searchMinimumPathFrom(ll src) {
    // 複数回呼ばれる度に計算する
    distances = vl(graph.nodes + 1, INF);
    srcs = vl(graph.nodes + 1, INF);

    priority_queue<ll> pq;
    distances[src] = 0;
    srcs[src] = -1;

    pq.push(src);
    while (!pq.empty()) {
      int u = pq.top();
      pq.pop();

      itrep(edge, fromPaths[u]) {
        int v = edge->to;
        ll w = edge->cost;
        if (distances[v] > distances[u] + w) {
          distances[v] = distances[u] + w;
          srcs[v] = u;
          pq.push(v);
        }
      }
    }
  };
  ll getDistance(ll n) { return distances[n]; }
  ll getFrom(ll n) { return srcs[n]; }
};

// ベルマンフォード O(|V||E|)
// 負コストが含まれていても最短経路問題を解くためのアルゴリズム。閉路の検出も可能
// 有向グラフ
class BellmanFord {
private:
  Graph graph;
  // 閉路が含まれるかは個々のノードごとに管理する必要あり
  vector<bool> hasNegativeCycles;
  vector<ll> distances;
  vl srcs;

public:
  BellmanFord(Graph graph) {
    ll nodes = graph.nodes + 1;

    this->graph = graph;
    distances = vector<ll>(nodes, INF);
    hasNegativeCycles = vector<bool>(nodes, false);
  }
  void searchMinimumPathFrom(ll src) {
    distances[src] = 0;

    for (ll i = 0; i < graph.nodes - 1; i++) {
      itrep(edge, graph.edges) {
        ll u = edge->from;
        ll v = edge->to;
        ll w = edge->cost;
        if (distances[u] != INF) {
          chmin(distances[v], distances[u] + w);
        }
      }
    }

    itrep(edge, graph.edges) {
      ll u = edge->from;
      ll v = edge->to;
      ll w = edge->cost;
      if (distances[u] == INF) {
        continue;
      }
      if (distances[u] + w < distances[v]) {
        hasNegativeCycles[v] = true;
      }
    }

    for (ll i = 0; i < graph.nodes; i++) {
      itrep(edge, graph.edges) {
        ll u = edge->from;
        ll v = edge->to;
        ll w = edge->cost;
        if (distances[u] == INF) {
          continue;
        }
        chmin(distances[v], distances[u] + w);
        if (hasNegativeCycles[u] == true) {
          hasNegativeCycles[v] = true;
        }
      }
    }
  }
  ll getDistance(ll n) { return distances[n]; }
  bool hasNegativeCycle(ll n) { return hasNegativeCycles[n]; }
  ll getFrom(ll n) { return srcs[n]; }
};

// O(V^3) 有向グラフ
class WarshallFloyd {
private:
  Graph graph;
  int nodes = this->graph.nodes + 1;
  vector<vector<ll>> distances;

public:
  WarshallFloyd(Graph graph) {
    this->graph = graph;
    nodes = this->graph.nodes + 1;
    this->distances = vector<vector<ll>>(nodes, vector<ll>(nodes, INF));
    itrep(edge, graph.edges) {
      int from = edge->from;
      int to = edge->to;
      int cost = edge->cost;
      distances[from][to] = cost;
    }
  }
  void searchMinimumPath() {
    for (int k = 0; k < nodes; k++) {
      for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
          if (distances[i][k] == INF || distances[k][j] == INF) {
            continue;
          }
          if (distances[i][k] + distances[k][j] < distances[i][j]) {
            distances[i][j] = distances[i][k] + distances[k][j];
          }
        }
      }
    }
  }
  ll getDistance(int from, int to) { return distances[from][to]; }
};

void solve(long long N, long long M, long long K) {
  mint n = N;
  mint m = M;

  combination comb(N * M);
  mint c = comb((n * m - 2).x, K - 2);

  mint ans = 0;

  mint sum = 0;
  rep(i, 0, M) { sum += (M - i) * i; }
  ans += n * n * sum * c;

  sum = 0;
  rep(i, 0, N) { sum += (N - i) * i; }
  ans += m * m * sum * c;

  print(ans.x);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  long long K;
  scanf("%lld", &K);
  solve(N, M, K);
  return 0;
}
