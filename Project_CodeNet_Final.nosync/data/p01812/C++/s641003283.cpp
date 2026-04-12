#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> d(m), rd(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
        d[i]--;
        rd[d[i]] = i; // dの逆写像
    }
    vector<vector<int>> v(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> v[i][j]; v[i][j]--;
        }
    }
    vector<vector<int>> g(1 << m);
    for (int i = 0; i < (1 << m); i++) {
        for (int r = 0; r < k; r++) {
            int t = 0;
            for (int j = 0; j < m; j++) {
                if ((i & (1 << j)) && rd[v[d[j]][r]] != -1) {
                    t |= (1 << rd[v[d[j]][r]]);
                }
            }
            g[i].push_back(t);
        }
    }
    //dump(g);
    // (1<<m)-1から0までの距離
    vector<int> dist((1 << m), -1);
    queue<int> que;
    que.push((1 << m) - 1);
    dist[(1 << m) - 1] = 0;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int u : g[v]) {
            if (dist[u] == -1) {
                que.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
    //dump(dist);
    cout << dist[0] << endl;
    return 0;
}
