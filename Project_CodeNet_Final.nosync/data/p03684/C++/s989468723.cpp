#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;

using ll = long long;
using Edge = tuple<ll, int, int>;   // (コスト, u, v)
using P = pair<ll, int>;    // (座標, id)

struct UnionFind {
    vector<int> parent;
    int set_num;

    UnionFind(int n) {
        parent.resize(n, -1);
        set_num = n;
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (size(x) < size(y)) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            set_num--;
        }
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    int find(int x) {
        if (parent[x] < 0) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    int size(int x) {
        return -parent[find(x)];
    }

    int size() {
        return set_num;
    }
};

int main() {
    int N;
    cin >> N;

    const int MAXN = 200000;
    static P xid[MAXN],
             yid[MAXN];
    
    for (int i = 0; i < N; i++) {
        cin >> xid[i].first >> yid[i].first;

        xid[i].second = yid[i].second = i;
    }
    sort(xid, xid + N);
    sort(yid, yid + N);

    vector<Edge> edges;
    for (int i = 0; i < N - 1; i++) {
        edges.emplace_back(xid[i + 1].first - xid[i].first, xid[i + 1].second, xid[i].second);
        edges.emplace_back(yid[i + 1].first - yid[i].first, yid[i + 1].second, yid[i].second);
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(N);
    ll ans = 0;
    for (Edge& e : edges) {
        ll cost;
        int u, v;
        tie(cost, u, v) = e;

        if (uf.is_same(u, v)) continue;

        uf.unite(u, v);
        ans += cost;
    }

    cout << ans << endl;

    return 0;
}
