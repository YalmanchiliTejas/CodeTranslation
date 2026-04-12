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

// a + b + cをprimeで割った値を返す
long long addMod(long long a, long long b) { return (a + b) % MOD; }

long long minusMod(long long a, long long b) { return (a + MOD - b) % MOD; }

long long multipleMod(long long a, long long b) { return (a * b) % MOD; }

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
      fromPaths[edge->to].push_back(Edge(edge->to, edge->from, edge->cost));
    }
  }
  void searchMinimumPathFrom(ll src) {
    // 複数回呼ばれる度に計算する
    this->distances = vl(graph.nodes + 1, INF);
    this->srcs = vl(graph.nodes + 1, INF);

    priority_queue<ll> pq;
    distances[src] = 0;
    srcs[src] = -1;

    pq.push(src);
    while (!pq.empty()) {
      int u = pq.top();
      pq.pop();

      itrep(edge, fromPaths[u]) {
        int v = edge->to;
        int w = edge->cost;
        if (distances[v] > distances[u] + w) {
          distances[v] = distances[u] + w;
          srcs[v] = u;
          pq.push(v);
        }
      }
    }
  };
  ll getDistance(ll n) { return this->distances[n]; }
  ll getFrom(ll n) { return this->srcs[n]; }
};

// ベルマンフォード O(|V||E|)
// 非負コストが含まれていても最短経路問題を解くためのアルゴリズム。閉路の検出も可能
class BellmanFord {
private:
  Graph graph;
  // 閉路が含まれるかは個々のノードごとに管理する必要あり
  vector<bool> hasNegativeCycles;
  vector<ll> distances;

public:
  BellmanFord(Graph graph) {
    this->graph = graph;
    this->distances = vector<ll>(this->graph.nodes + 1, INF);
    this->hasNegativeCycles = vector<bool>(this->graph.nodes + 1, false);
  }
  void searchMinimumPathFrom(ll src) {
    this->distances[src] = 0;

    for (ll i = 0; i < graph.nodes - 1; i++) {
      itrep(edge, graph.edges) {
        ll u = edge->from;
        ll v = edge->to;
        ll w = edge->cost;
        if (this->distances[u] + w < this->distances[v]) {
          this->distances[v] = this->distances[u] + w;
        }
      }
    }

    itrep(edge, graph.edges) {
      ll u = edge->from;
      ll v = edge->to;
      ll w = edge->cost;
      if (this->distances[u] + w < this->distances[v]) {
        this->hasNegativeCycles[v] = true;
      }
      if (this->hasNegativeCycles[u] == true) {
        this->hasNegativeCycles[v] = true;
      }
    }
  }
  ll getDistance(ll n) { return this->distances[n]; }
  bool hasNegativeCycle(ll n) { return this->hasNegativeCycles[n]; }
};

void solve(long long N, std::vector<long long> A) {
  multiset<ll> colorMinNums;
  rep(i, 0, N) {
    auto it = colorMinNums.lower_bound(A[i]);
    if (it == colorMinNums.begin()) {
      colorMinNums.insert(A[i]);
    } else {
      colorMinNums.erase(--it);
      colorMinNums.insert(A[i]);
    }
  }
  print(colorMinNums.size());
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
