#include <tuple>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int> > > adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--;  b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    long long sum = 0;
    // MST
    vector<vector<pair<int, int> > > temp(n);
    bool visited[n] = {};
    visited[0] = true;
    priority_queue<tuple<int, int, int> > pq; // cost, src, dst
    int depth[n] = {};
    for (auto e : adj[0]) pq.push(make_tuple(-e.second, 0, e.first));
    while (!pq.empty()) {
        auto e = pq.top(); pq.pop();
        int cost = -get<0>(e), src = get<1>(e), dst = get<2>(e);
        if (visited[dst]) continue;
        visited[dst] = true;
        depth[dst] = depth[src] + 1;
        temp[src].push_back({dst, cost});
        sum += cost;
        for (auto e : adj[dst])
            if (!visited[e.first]) pq.push(make_tuple(-e.second, dst, e.first));
    }
    temp.swap(adj);

    pair<int, int> par[12][n] = {};
    for (int k = 0; 1<<k < n; k++)
        for (int i = 0; i < n; i++)
            if (k == 0) 
                for (auto e : adj[i])
                    par[0][e.first] = {i, e.second};
            else if (depth[i] >= 1<<k) {
                int a1 = par[k-1][i].first,
                    a2 = par[k-1][a1].first,
                    cost1 = par[k-1][i].second,
                    cost2 = par[k-1][a1].second;
                par[k][i] = {a2, max(cost1, cost2)};
            } else
                par[k][i] = {-1, -1};

    // for (int k = 0; 1<<k < n; k++)
    //     for (int i = 0; i < n; i++)
    //         cout << i << ' ' << k << ' ' << par[k][i].second << endl;

    int q; cin >> q;
    while (q--) {
        int s, t; cin >> s >> t;
        s--; t--;
        if (depth[s] < depth[t]) swap(s, t);
        int mx = 0;
        for (int d = depth[s] - depth[t], k = 0; d > 0; k++) {
            if (d & 1<<k) {
                mx = max(mx, par[k][s].second);
                s = par[k][s].first;
                d ^= (1<<k);
            }
            // cout << k << ' ' << mx << endl;
        }
        if (s != t) {
            for (int k = 11; k >= 0; k--) {
                if (1<<k <= depth[s] && par[k][s].first != par[k][t].first) {
                    mx = max(mx, max(par[k][s].second, par[k][t].second));
                    s = par[k][s].first;
                    t = par[k][t].first;
                }
            }
            mx = max(mx, max(par[0][s].second, par[0][t].second));
        }
        cout << sum - mx << endl;
    }
}
