#include <bits/stdc++.h>
using namespace std;
#define VI vector<int>

void dfs(int node, int f, vector<VI> &G, vector<VI> &C, VI &d, int val) {
    d[node] = val;
    for(int i = 0; i < int(G[node].size()); ++i) {
        int temp = G[node][i];
        if(temp == f)
            continue;
        dfs(temp, node, G, C, d, max(val, C[node][i]));
    }
}

int main() {
    //ifstream cin("testA.in");

    int n, m; cin >> n >> m;
    vector<int> a(m, 0), b(m, 0), c(m, 0);
    vector<pair<int, int>> edges;

    for(int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    for(int i = 0; i < m; ++i) {
        edges.push_back({c[i], i});
    }

    sort(edges.begin(), edges.end());

    vector<int> dad(n, 0), sz(n, 0);
    for(int i = 0; i < n; ++i)
        dad[i] = i;

    auto f = [&] (int x) {
        int root = x;
        int steps = 0;
        while(root != dad[root]) {
            root = dad[root];
            ++steps;
        }
        while(x != root) {
            int temp = dad[x];
            dad[x] = root;
            x = temp;
        }
        return root;
    };

    auto unite = [&] (int a, int b) {
        dad[a] = b;
    };
    
    vector<vector<int>> G(n), C(n);
    long long ans = 0;

    for(auto edge : edges) {
        int x = a[edge.second];
        int y = b[edge.second];
        if(f(x) != f(y)) {
            ans += edge.first;
            unite(f(x), f(y));
            G[x].push_back(y);
            G[y].push_back(x);
            C[x].push_back(edge.first);
            C[y].push_back(edge.first);
        }
    }
        
    vector<vector<int>> d(n, vector<int> (n, 0));
    
    for(int i = 0; i < n; ++i) {
        int now = 0;
        dfs(i, -1, G, C, d[i], now);
    }

    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y;
        x--;y--;
        cout << ans - d[x][y] << "\n";
    }
}