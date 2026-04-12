#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;

struct UnionFind {
    static const int Max = 100010;
    int par[Max];
    int rank[Max];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

const int MAXE = 100010 * 2;
struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

edge es[MAXE];
int V, E;

ll kruskal() {
    sort(es, es+E, comp);
    UnionFind uf;
    uf.init(V);
    ll res = 0;
    for (int i=0; i<E; ++i) {
        edge e = es[i];
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> V;

    using P = pair< pair<int, int>, int>;
    vector< P > v(V);

    rep(i, V) {
        P a; int x, y;
        cin >> x >> y;
        a = { {x, y}, i };
        v[i] = a;
    }

    sort(v.begin(), v.end(), [](P& a, P& b) {
        return a.first.first < b.first.first;
    });

    rep(i, V-1) {
        es[E++] = { v[i].second, v[i+1].second, min((int)abs(v[i].first.first - v[i+1].first.first), (int)abs(v[i].first.second - v[i+1].first.second)) };
    }

    sort(v.begin(), v.end(), [](P& a, P& b) {
        return a.first.second < b.first.second;
    });

    rep(i, V-1) {
        es[E++] = { v[i].second, v[i+1].second, min((int)abs(v[i].first.first - v[i+1].first.first), (int)abs(v[i].first.second - v[i+1].first.second)) };
    }

    cout << kruskal() << endl;

}
