#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct union_find {
  std::vector<int> rank, par;
  int v_size;
  union_find() {}

  // 初期化
  union_find(int n) {
    v_size = n;
    rank.resize(n, 0);
    par.resize(n);
    for(int i=0;i<n;i++) {
      par[i] = i;
    }
  }

  // 木の根を求める
  int find(int x) {
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }

  // xとyの属する集合を併合
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if(rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

  // xとyが同じ集合に属するか否か
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // グループの個数を数える
  int count() {
    std::set<int> st;
    for(int i=0;i<v_size;i++) {
      st.insert(find(i));
    }
    return st.size();
  }

};
struct edge { int u, v, cost; };
bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

const int MAX_E = 100010;
//edge es[MAX_E];
vector<edge> es;
ll V, E;

ll kruskal() {
  std::sort(es.begin(), es.end(), comp);
  union_find uf(V);
  ll res = 0;
  for(int i=0;i<E;i++) {
    edge e = es[i];
    if(!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  vector<pair<ll, ll> > x(N), y(N);
  for(int i=0;i<N;i++) {
    ll xi, yi;
    cin >> xi >> yi;
    x[i] = make_pair(xi, i);
    y[i] = make_pair(yi, i);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  for(int i=0;i<N-1;i++) {
    edge ex;
    ex.u = x[i].second;
    ex.v = x[i+1].second;
    ex.cost = abs(x[i].first-x[i+1].first);
    es.push_back(ex);

    edge ey;
    ey.u = y[i].second;
    ey.v = y[i+1].second;
    ey.cost = abs(y[i].first-y[i+1].first);
    es.push_back(ey);
  }

  V = N;
  E = es.size();
  ll ans = kruskal();
  cout << ans << endl;
}
