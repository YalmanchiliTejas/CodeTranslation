#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MX = 100 * 1000 + 7;
vector<int> g[MX];

bool fl = false;

int dfs(int v, int p = -1) {
    int sm = 0;
    for (int to : g[v]) {
        if (to != p) {
            sm += dfs(to, v);
        }
    }
    if (sm >= 2) {
        fl = true;
    }
    return sm == 0;
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (dfs(1) == 1) {
        fl = true;
    }
    if (fl) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    return 0;
}


