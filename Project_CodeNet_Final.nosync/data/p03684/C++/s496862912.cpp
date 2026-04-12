#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(it,o) for(auto it = (o).begin(); it != (o).end(); ++ it)
typedef long long ll;
struct edge { int to; int from; int cost; };
struct vertex { int x; int y; int idx;};

struct UnionFind {
    vector<int> par; // 親
    vector<int> rank; // 木の深さ

    UnionFind() {
    }

    // n要素で初期化
    void init(int n) {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    // 木の根を求める
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            return par[x] = find(par[x]);
        }
    }

    // xとyの属する集合を併合
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }

        if (rank[x] < rank[y]) {
            par[x] = y;
        }
        else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    // xとyが同じ集合に属するか否か
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int cost(const vertex& v1, const vertex& v2) {
    return min(abs(v1.x - v2.x), abs(v1.y - v2.y));
}

bool compX(const vertex& v1, const vertex& v2) {
    return v1.x < v2.x;
}

bool compY(const vertex& v1, const vertex& v2) {
    return v1.y < v2.y;
}

bool compCost(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

vector<vertex> vt;
vector<edge> es;
UnionFind uf;

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int n;
        in >> n;
        vt.clear();
        vt.resize(n);
        rep(i, n) {
            in >> vt[i].x >> vt[i].y;
            vt[i].idx = i;
        }
        
        es.clear();
        uf.init(n);
        sort(vt.begin(), vt.end(), compX);
        int c;
        edge e;
        rep(i, n - 1) {
            e.from = vt[i + 0].idx;
            e.to = vt[i + 1].idx;
            e.cost = cost(vt[i + 0], vt[i + 1]);
            es.push_back(e);
        }

        sort(vt.begin(), vt.end(), compY);
        rep(i, n - 1) {
            e.from = vt[i + 0].idx;
            e.to = vt[i + 1].idx;
            e.cost = cost(vt[i + 0], vt[i + 1]);
            es.push_back(e);
        }

        sort(es.begin(), es.end(), compCost);

        ll res = 0;
        each(it, es) {
            if (!uf.same(it->to, it->from))
            {
                uf.unite(it->to, it->from);
                res += it->cost;
            }
        }

        out << res << endl;
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}

#include <fstream>
#include <iostream>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    istream& in = cin;
    ostream& out = cout;
    solve(in, out);
    return 0;
}
