#include<bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i, n) for(int i=0;i<(n);++i)
#define INF (1ll<<60)
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<int, pii> pip;

int N;
ppi px[100100];
ppi py[100100];
vector<pip> edge;

struct UF {
    int N;
    const static int size = 100100;
    int par[size];

    UF(int n) {
        N = n;
        rep(i, n) {
            par[i] = i;
        }
    }

    int root(int x) {
        if (par[x] == x)return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        if (root(x) != root(y)) {
            par[root(x)] = root(y);
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

signed main() {
    cin >> N;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        px[i] = ppi(pii(x, y), i);
        py[i] = ppi(pii(y, x), i);
    }
    sort(px, px + N);
    sort(py, py + N);
    rep(i, N - 1) {
        int x0 = px[i].first.first;
        int x1 = px[i + 1].first.first;
        int cost = x1 - x0;
        int i0 = px[i].second;
        int i1 = px[i + 1].second;
        edge.push_back(pip(cost, pii(i0, i1)));
    }
    rep(i, N - 1) {
        int y0 = py[i].first.first;
        int y1 = py[i + 1].first.first;
        int cost = y1 - y0;
        int i0 = py[i].second;
        int i1 = py[i + 1].second;
        edge.push_back(pip(cost, pii(i0, i1)));
    }
    sort(edge.begin(), edge.end());

    UF uf(N + 10);
    int ans = 0;
    rep(i, edge.size()) {
        pii p = edge[i].second;
        if (!uf.same(p.first, p.second)) {
            ans += edge[i].first;
            uf.unite(p.first, p.second);
        }
    }
    cout << ans << endl;
    return 0;
}