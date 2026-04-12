/*
 * C.cpp
 *
 *  Created on: 2017/06/18
 *      Author: jin
 */

#define MYDEBUG
#include <bits/stdc++.h>

#ifdef MYDEBUG
#define dbp(x) cout<<#x<<": "<<x<<endl
#define dbp2(x,y) cout<<#x<<","<<#y<<": "<<x<<","<<y<<endl
#define dbp3(x,y,z) cout<<#x<<","<<#y<<","<<#z<<": "<<x<<","<<y<<","<<z<<endl
#define dbp4(w,x,y,z) cout<<#w<<","<<#x<<","<<#y<<","<<#z<<": "<<w<<","<<x<<","<<y<<","<<z<<endl
#define ifcin(x) std::ifstream cin(x)
#else
#define dbp(x)
#define dbp2(x,y)
#define dbp3(x,y,z)
#define dbp4(w,x,y,z)
#define ifcin(x)
#endif
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for(int i=from; i<to; ++i)
#define REP(i, from, to) for(int i=from; i<=to; ++i)
#define EPS = 1e-14;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;
using std::swap;
using std::string;
using std::fill;
using std::pair;
using std::sort;
using std::reverse;
using std::pair;
using std::greater;
using std::priority_queue;
using std::ostream;

template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& v) {
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i] << endl;
  }
  return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  size_t last = v.size() - 1;
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last) {
      out << ",";
    }
  }
  out << "]";
  return out;
}
struct unionfind {
  vector<int> par;
  vector<int> rank;
  unionfind(int n) {
    par = vector<int>(n);
    rank = vector<int>(n);
    rep(i,0,n)
    { //0オリジン
      par[i] = i;
      rank[i] = 1;
    }
  }

  int find(int x) {
    if (par[x] == x) {
      return x;
    }
    return par[x] = find(par[x]);
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  void unite(int x, int y) { //rank[x] > rank[y]を保つ
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    if (rank[x] < rank[y]) {
      swap(x, y);
    }
    par[y] = x;
    rank[x] += rank[y];
    rank[y] = 0;
  }

  int size(int x) {
    return rank[x];
  }
};

struct edge {
  int from, to;
  double cost;
  edge(int from, int to, double cost) {
    this->from = from;
    this->to = to;
    this->cost = cost;
  }

  edge() {
    *this = edge(-1, -1, -1);
  }

  bool operator<(const edge& e) const {
    return cost < e.cost;
  }
};

class Graph {
public:
  static ll kruskal(vector<edge>& es, int n) {
    sort(all(es));
    ll min_cost = 0;
    unionfind uf(n);
    rep(i,0,(int)es.size())
    {
      edge &e = es[i];
      if (!uf.same(e.from, e.to)) {
        min_cost += e.cost;
        uf.unite(e.from, e.to);
      }
    }
    return min_cost;
  }
};

int N;
typedef pair<int, int> P;
const int MAX_N = 100010;
vector<P> X, Y;
int dx[MAX_N], dy[MAX_N];
vector<edge> G;
void solve() {
  cin >> N;
  rep(i,0,N)
  {
    int x, y;
    cin >> x >> y;
    X.push_back(P(x, i));
    Y.push_back(P(y, i));
  }
  std::sort(all(X));
  std::sort(all(Y));
  rep(i,1,N)
  {
    dx[i] = X[i].first - X[i - 1].first;
    dy[i] = Y[i].first - Y[i - 1].first;
    G.push_back(edge(X[i].second, X[i - 1].second, dx[i]));
    G.push_back(edge(Y[i].second, Y[i - 1].second, dy[i]));
  }
  cout << Graph::kruskal(G, N) << endl;
}

int main() {
  solve();
}

