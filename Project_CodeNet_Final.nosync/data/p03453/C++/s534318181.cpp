#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;
long d[2][111111], e[2][111111];
int c[111111];
tuple<int, int, int> h[222222];
int main() {
    int n, m, s, t, p = 1e9 + 7;
    cin >> n >> m >> s >> t;
    g.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        h[i] = {u, v, d};
        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }
    for(int j = 0; j < 2; j++) {
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> q;
        fill(d[j], d[j] + n + 1, 1e18);
        fill(c, c + n + 1, 0);
        q.emplace(d[j][s] = 0, s);
        e[j][s] = 1;
        while(!q.empty()) {
            int u = q.top().second;
            q.pop();
            if(c[u])
                continue;
            c[u] = 1;
            for(auto [v, i] : g[u]) {
                auto l = d[j][u] + i;
                if(d[j][v] < l)
                    continue;
                if(d[j][v] > l) {
                    e[j][v] = 0;
                    d[j][v] = l;
                    q.emplace(d[j][v], v);
                }
                (e[j][v] += e[j][u]) %= p;
            }
        }
        swap(s, t);
    }
    auto r = e[0][t] * e[0][t] % p;
    for(int i = 1; i <= n; i++) {
        auto x = d[0][i];
        if(x == d[1][i] && x + x == d[0][t]) {
            auto a = e[0][i] * e[1][i] % p;
            (r -= a * (a - p)) %= p;
        }
    }
    for(int i = 0; i < m; i++) {
        auto [u, v, l] = h[i];
        for(int j = 0; j < 2; j++) {
            swap(u, v);
            auto x = d[0][u], y = d[1][v], z = d[0][t];
            if(x + l + y == z && x + x < z && y + y < z) {
                auto a = e[0][u] * e[1][v] % p;
                (r -= a * (a - p)) %= p;
            }
        }
    }
    cout << r << endl;
    return 0;
}
