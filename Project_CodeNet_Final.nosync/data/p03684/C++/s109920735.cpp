#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll;
 
struct UnionFind {vector<int> par, cnt;
    UnionFind(int NV) { par.clear(); cnt.resize(NV, 1); rep(i, 0, NV) par.push_back(i); }
    void reset() { rep(i, 0, cnt.size()) cnt[i] = 1; rep(i, 0, par.size()) par[i] = i; }
    int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
    void operator()(int x, int y) {x = operator[](x); y = operator[](y);
        if (x != y) par[x] = y, cnt[y] += cnt[x];}};
 
int N;
void _main() {
    cin >> N;
    vector<pair<int, int>> va, vb;
    rep(i, 0, N) {
        int x, y; cin >> x >> y;
        va.push_back({ x, i });
        vb.push_back({ y, i });
    }
 
    vector<tuple<int, int, int>> edges;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    rep(i, 0, N - 1) {
        edges.push_back(make_tuple( va[i + 1].first - va[i].first, va[i].second, va[i + 1].second ));
        edges.push_back(make_tuple( vb[i + 1].first - vb[i].first, vb[i].second, vb[i + 1].second));
    }
    sort(edges.begin(), edges.end());
 
    UnionFind uf(N);
    ll ans = 0;
    for (auto p : edges) {
        int x, y, c;
        tie(c, x, y) = p;
 
        if (uf[x] != uf[y]) {
            uf(x, y);
            ans += c;
        }
    }
    cout << ans << endl;
}