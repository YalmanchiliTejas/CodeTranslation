#include "bits/stdc++.h"
using namespace std;

struct UnionFind {
        vector<int> par;
        UnionFind(int n) : par(n) { for (int i = 0; i < n; i++) par[i] = i; }
        int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
        bool same(int x, int y) { return find(x) == find(y); }
        void unite(int x, int y) { x = find(x); y = find(y); if (x == y) return; par[x] = y; }
};

struct Edge {
        int a, b, cost;
};

bool comp(const Edge& e1, const Edge& e2) {
        return e1.cost < e2.cost;
}

int main() {
        int n;
        cin >> n;
        vector<long long> x(n), y(n);
        vector<pair<long long, int>> xx;
        vector<pair<long long, int>> yy;
        for (int i = 0; i < n; i ++) {
                cin >> x[i] >> y[i];
                xx.push_back(make_pair(x[i], i));
                yy.push_back(make_pair(y[i], i));
        }
        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
        vector<Edge> e;
        for (int i = 0; i < n - 1; i ++) {
                long long d = abs(xx[i].first - xx[i + 1].first);
                Edge ee;
                ee.a = xx[i].second;
                ee.b = xx[i + 1].second;
                ee.cost = d;
                e.push_back(ee);
        }
        for (int i = 0; i < n - 1; i ++) {
                long long d = abs(yy[i].first - yy[i + 1].first);
                Edge ee;
                ee.a = yy[i].second;
                ee.b = yy[i + 1].second;
                ee.cost = d;
                e.push_back(ee);
        }
        UnionFind uf(n);
        sort(e.begin(), e.end(), comp);
        long long ans = 0;
        for (int i = 0; i < e.size(); i ++) {
                Edge ee = e[i];
                if (!uf.same(ee.a, ee.b)) {
                        uf.unite(ee.a, ee.b);
                        ans += ee.cost;
                }
        }
        cout << ans << endl;
        return 0;
}

