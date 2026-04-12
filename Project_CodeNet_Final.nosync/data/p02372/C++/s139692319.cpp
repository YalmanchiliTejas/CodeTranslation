#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using edge = pair<int, long long>;
using Graph = vector<vector<edge>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

Graph g;
vector<long long> depth;
void dfs(int u, int p) {
    for (auto &e: g[u]) if (e.first != p) {
        dfs(e.first, u);
        chmax(depth[u], depth[e.first] + e.second);
    }
}
vector<long long> height;
void dfs2(int u, int p, int d_par) {
    vector<pair<long long, int>> d_child;
    d_child.emplace_back(0, -1);        // sentinel
    for (auto &e: g[u]) {
        long long dv = (e.first == p ? d_par : depth[e.first]) + e.second;
        d_child.emplace_back(dv, e.first);
    }
    sort(d_child.rbegin(), d_child.rend());
    height[u] = d_child[0].first;
    for (auto &e: g[u]) if (e.first != p) {
        long long nd_par = d_child[d_child[0].second == e.first].first;
        dfs2(e.first, u, nd_par);
    }
}

int main() {
    int n; cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t, w; cin >> s >> t >> w;
        g[s].emplace_back(t, w);
        g[t].emplace_back(s, w);
    }
    depth.resize(n);
    dfs(0, -1);
    height.resize(n);
    dfs2(0, -1, 0);
    for (auto h: height) cout << h << endl;
    return 0;
}
