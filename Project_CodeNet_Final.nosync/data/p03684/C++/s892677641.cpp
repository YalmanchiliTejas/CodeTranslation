#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

struct UnionFind {
    UnionFind(int n) : p(n, -1) {}
    int root(int u) {
        return p[u] < 0 ? u : p[u] = root(p[u]);
    }
    bool same(int u, int v) {
        return root(u) == root(v);
    }
    void unite(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
    }
    vector<int> p;
};

struct Edge {
    bool operator<(Edge o) { return c < o.c; }
    int i, j;
    int c;
};

int main() {
    int n;
    cin >> n;

    vector<int[2]> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i][0] >> r[i][1];
    }

    vector<Edge> e;
    e.reserve(n * 2);
    vector<int> p(n);

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        sort(p.begin(), p.end(), [&](int i0, int i1) {
            return r[i0][j] < r[i1][j];
        });

        for (int i = 1; i < n; i++) {
            e.push_back({ p[i], p[i - 1], abs(r[p[i]][j] - r[p[i - 1]][j]) });
        }
    }

    sort(e.begin(), e.end());
    UnionFind uf(e.size());
    int c = 0, k = 0;

    for (const Edge& o : e) {
        if (uf.same(o.i, o.j)) continue;
        uf.unite(o.i, o.j);
        c += o.c;
        if (++k == n - 1) break;
    }

    cout << c << endl;

    return 0;
}