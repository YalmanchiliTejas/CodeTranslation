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
#define arep(X, Y) for (auto(X) : Y)
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl
#define printDouble(x) cout << fixed << setprecision(13) << x << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

using decendingQueue = priority_queue<ll, vl>;              //降順
using ascendingQueue = priority_queue<ll, vl, greater<ll>>; //昇順

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int INT_INF = 1e9;
const ll LL_INF = 1e18;
const int mod = 1000000007;

template <class T> void mySort(vector<T> &X, bool isAscending) {
  // 昇順
  if (isAscending) {
    sort(all(X));
  } else {
    // 降順
    sort(all(X), greater<T>());
  }
}

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
    for (auto edge : graph.edges) {
      if (!uf.same(edge.from, edge.to)) {
        uf.unite(edge.from, edge.to);
        MinimumSpanningTree.push_back(edge);
      }
    }
  }

public:
  Kruskal(Graph graph) { this->graph = graph; }
  ll getMinimumSpanningTreeCost() {
    searchMinimumSpanningTree();
    ll cost = 0;
    for (auto tr : MinimumSpanningTree) {
      cost += tr.cost;
    }
    return cost;
  }
};

// ダイクストラ法 O((E+V)logV)
// 最小経路問題を解くためのアルゴリズム。辺の重みに負数を含む場合は利用不可
// 無向グラフの場合はコメントアウト箇所をコメントイン
class Dijkstra {
private:
  Graph graph;
  map<ll, vector<Edge>> fromPaths;
  vl distances;
  vl srcs;

public:
  Dijkstra(Graph graph) {
    this->graph = graph;
    for (auto edge : graph.edges) {
      fromPaths[edge.from].push_back(edge);
      // fromPaths[edge->to].push_back(Edge(edge->to, edge->from, edge->cost));
    }
  }
  void searchMinimumPathFrom(ll src) {
    // 複数回呼ばれる度に計算する
    distances = vl(graph.nodes + 1, LL_INF);
    srcs = vl(graph.nodes + 1, LL_INF);

    // 距離が近い順番に捜査していく
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    distances[src] = 0;
    srcs[src] = -1;

    pq.push(mp(0ll, src));
    while (!pq.empty()) {
      int u = pq.top().second;
      double uw = pq.top().first;
      pq.pop();

      if (distances[u] < uw) {
        continue;
      };

      for (auto edge : fromPaths[u]) {
        int v = edge.to;
        ll w = edge.cost;
        if (distances[v] > distances[u] + w) {
          distances[v] = distances[u] + w;
          srcs[v] = u;
          pq.push(mp(distances[v], v));
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
    distances = vector<ll>(nodes, LL_INF);
    hasNegativeCycles = vector<bool>(nodes, false);
  }
  void searchMinimumPathFrom(ll src) {
    distances[src] = 0;

    for (ll i = 0; i < graph.nodes - 1; i++) {
      for (auto edge : graph.edges) {
        ll u = edge.from;
        ll v = edge.to;
        ll w = edge.cost;
        if (distances[u] != LL_INF) {
          chmin(distances[v], distances[u] + w);
        }
      }
    }

    for (auto edge : graph.edges) {
      ll u = edge.from;
      ll v = edge.to;
      ll w = edge.cost;
      if (distances[u] == LL_INF) {
        continue;
      }
      if (distances[u] + w < distances[v]) {
        hasNegativeCycles[v] = true;
      }
    }

    for (ll i = 0; i < graph.nodes; i++) {
      for (auto edge : graph.edges) {
        ll u = edge.from;
        ll v = edge.to;
        ll w = edge.cost;
        if (distances[u] == LL_INF) {
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
    this->distances = vector<vector<ll>>(nodes, vector<ll>(nodes, LL_INF));
    for (auto edge : graph.edges) {
      int from = edge.from;
      int to = edge.to;
      int cost = edge.cost;
      distances[from][to] = cost;
    }
  }
  void searchMinimumPath() {
    for (int k = 0; k < nodes; k++) {
      for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
          if (distances[i][k] == LL_INF || distances[k][j] == LL_INF) {
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

template <typename T> class SegmentTree {
  int n = 1; // 最下段のノード数. ただし、2の冪乗
  vector<T> data;

  T init;                      // 初期値
  function<T(T, T)> mergeFunc; // 子ノードのmerge方法

public:
  SegmentTree(int N, function<T(T, T)> _mergeFunc, T _init) {
    mergeFunc = _mergeFunc;
    init = _init;

    while (n < N) {
      n *= 2;
    }

    data = vector<T>(n * 2 - 1, _init); // 2の冪乗で確保が必要
  }

  // i番目の値(0-indexed)をxに変更
  // O(logN)
  void update(int i, T v) {
    // 葉のノード
    i += n - 1;
    data[i] = v;

    // 親も更新
    while (i > 0) {
      i = (i - 1) / 2; //親のindex
      data[i] =
          mergeFunc(data[i * 2 + 1], data[i * 2 + 2]); //親から見た子のindex
    }
  }

  // i番目の値を返却
  T get(int i) { return data[i + n - 1]; }

  // [a, b)のmergeFuncを求めるクエリ
  // ノードk（空間[l, r)が担当）が答える. ノード0の根から探索する
  // 呼び出しはquery(a, b). その他の引数は再帰処理のため
  // O(logN)
  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    // 最初の呼び出し
    if (r < 0) {
      return query(a, b, k, l, n);
    }

    // 区間が被らない場合
    if (r <= a || b <= l) {
      return init;
    }

    // 完全に含む場合
    if (a <= l && r <= b) {
      return data[k];
    }

    // 部分的に含む場合. 子ノードに聞く
    T left = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T right = query(a, b, k * 2 + 2, (l + r) / 2, r);

    return mergeFunc(left, right);
  }
};

void solve(std::string S) {
  map<char, int> cnts;
  rep(i, 0, S.size()) { cnts[S[i]]++; }

  if (cnts.size() == 2) {
    print("Yes");
  } else {
    print("No");
  }
}

int main() {
  std::string S;
  std::cin >> S;
  solve(S);
  return 0;
}
