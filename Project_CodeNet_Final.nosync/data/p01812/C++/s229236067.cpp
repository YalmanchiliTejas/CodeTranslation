#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < (n); i++)

int n, m, k;
vector<vector<int> > E(1 << 17);
vector<int> dis(1 << 17, -1);
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (int j = 0; j < E[s].size(); j++) {
            int next = E[s][j];
            if (dis[next] == -1) {
                q.push(next);
                dis[next] = dis[s] + 1;
                // cout << next << " " << dis[next] << endl;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i, j;
    cin >> n >> m >> k;
    int d[m];
    for (i = 0; i < m; i++) {
        cin >> d[i];
    }
    vector<vector<int> > w(n, vector<int>(k, -1));
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            int v;
            cin >> v;
            for (int l = 0; l < m; l++) {
                if (v == d[l]) w[i][j] = (1 << l);
            }
        }
    }

    for (i = 0; i < (1 << m); i++) {
        for (int l = 0; l < k; l++) {
            int nex = 0;
            for (j = 0; j < m; j++) {
                if (((i >> j) & 1) == 0) continue;
                if (w[d[j] - 1][l] >= 0) nex |= w[d[j] - 1][l];
            }
            if (nex != i) {
                E[nex].push_back(i);
                // cout << nex << " " << i << endl;
            }
        }
    }

    q.push(0);
    dis[0] = 0;
    bfs();
    cout << dis[(1 << m) - 1] << endl;
}

