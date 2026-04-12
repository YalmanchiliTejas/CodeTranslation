#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[56], b[56];
int graph[9][9];

bool seen[9];
int ans = 0;

void dfs(int node) {
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) break;
        if (i == n) {
            ans++;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && !seen[i]) {
            seen[i] = true;
            dfs(i);
            seen[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) graph[i][j] = 0;
    }
    for (int i = 0; i < m; i++) {
        graph[a[i]][b[i]] = 1;
        graph[b[i]][a[i]] = 1;
    }

    for (int i = 1; i <= n; i++) seen[i] = false;
    seen[1] = true;
    dfs(1);

    cout << ans << endl;
}
