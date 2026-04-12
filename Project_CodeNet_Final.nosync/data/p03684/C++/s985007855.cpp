#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()
#define INF 1000000009

class UnionFind {
private:
    int n;
    vector<int> par;
public:
    UnionFind(int n) : n(n), par(n, -1) {}

    int root(int x) { return par[x] < 0 ? x : par[x] = root(par[x]); }

    bool same(int x, int y) { return root(x) == root(y); }

    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x != y) {
            if (par[x] > par[y]) swap(x, y);
            par[x] += par[y];
            par[y] = x;
        }
    }

    int set_size(int x) { return -par[root(x)]; }

    int size() const { return n; }
};

int main() {
    int N, x, y;
    pii X[100000], Y[100000];
    cin >> N;
    REP(i, N) {
        cin >> x >> y;
        X[i] = {x, i};
        Y[i] = {y, i};
    }
    sort(X, X + N);
    sort(Y, Y + N);

    vector<pair<int, pii>> edges;
    REP(i, N - 1) {
        edges.push_back({X[i + 1].first - X[i].first, {X[i + 1].second, X[i].second}});
        edges.push_back({Y[i + 1].first - Y[i].first, {Y[i + 1].second, Y[i].second}});
    }
    sort(edges.begin(), edges.begin() + (N - 1) * 2);

    UnionFind uf(N);
    int cost = 0;
    REP(i, (N - 1) * 2) {
        auto e = edges[i];
        if (!uf.same(e.second.first, e.second.second)) {
            uf.unite(e.second.first, e.second.second);
            cost += e.first;
        }
        if (uf.set_size(0) == N) break;
    }
    cout << cost << endl;
    return 0;
}