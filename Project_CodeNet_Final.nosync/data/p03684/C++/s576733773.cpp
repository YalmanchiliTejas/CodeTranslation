// 5/26
// 2-5-3 最小全域木
// 類題
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// UnionFind
struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

// クラスカル法ではグラフは辺の集合として定義（無向が前提）
struct Edge {
    int u;
    int v;
    int cost;
    Edge(int u, int v, int c) : u(u), v(v), cost(c) { }
    // Edge(int u_, int v_, int c) : u(u_), v(v_), cost(c) { }
    // Edge(int u, int v, int c) {
    //     this->u = u;
    //     this->v = v;
    //     this->cost = c;
    // }
    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
};
using Graph = vector<Edge>;

ll kruskal(int N, Graph& es) {  // ここでconstはだめ。ソートするから。いっぱいエラー出る。http://nocotan.github.io/%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0/2017/01/27/mst-copy.html
    sort(es.begin(), es.end());
    UnionFind uf(N);
    ll res = 0;
    for (auto e : es) {
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    Graph es;
    vector<P> Vx, Vy;  // {x or y coordinate, index}

    rep(i, N) {
        int x, y;
        cin >> x >> y;
        Vx.push_back({x, i});
        Vy.push_back({y, i});
    }

    sort(Vx.begin(), Vx.end());
    sort(Vy.begin(), Vy.end());

    // cout << "Vx-----" << endl;
    // rep(i, N) cout << Vx[i].first << " " << Vx[i].second << endl;
    // cout << "Vy-----" << endl;
    // rep(i, N) cout << Vy[i].first << " " << Vy[i].second << endl;

    rep(i, N - 1) {
        int u, v, cost;

        u = Vx[i].second;
        v = Vx[i + 1].second;
        cost = Vx[i + 1].first - Vx[i].first;
        // cout << cost << endl;
        es.push_back(Edge(u, v, cost));

        u = Vy[i].second;
        v = Vy[i + 1].second;
        cost = Vy[i + 1].first - Vy[i].first;
        // cout << cost << endl;
        es.push_back(Edge(u, v, cost));
    }

    // rep(i, N) {
    //     for (int j = i + 1; j < N; j++) {
    //         int cost = min(abs(V[i].first - V[j].first), abs(V[i].second - V[j].second));
    //         es.push_back(Edge(i, j, cost));
    //     }
    // }

    cout << kruskal(N, es) << endl;
}
