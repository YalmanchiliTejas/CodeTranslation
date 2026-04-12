#include <bits/stdc++.h>
#define ll long long
using namespace std;

int used[8], ans = 0;
vector<vector<int> > g(8);
int n, m;

void dfs(int u) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) sum++;
    }
    if (sum == n - 1) ans++;
    for (int i = 0; i < (int)g[u].size(); i++) {
        if (used[g[u][i]] == 0) {
            used[u] = 1;
            dfs(g[u][i]);
            used[u] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}