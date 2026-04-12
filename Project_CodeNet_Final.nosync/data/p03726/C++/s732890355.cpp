#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> II;

const int N = (int) 1e5 + 10;
int n, deg[N], c[N], h[N];
vector<int> adj[N];

void DFS(int u, int p = -1) {
    c[u] = 1;
    for (int i = 0; i < (int) adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v != p) {
            h[v] = h[u] + 1;
            DFS(v, u);
            c[u] ^= c[v];
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("inp", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v); deg[u]++;
        adj[v].push_back(u); deg[v]++;
    }

    DFS(1);
    for (int u = 1; u <= n; ++u) {
        int cnt[2] = {0};
        for (int i = 0; i < (int) adj[u].size(); ++i)
            if (h[adj[u][i]] > h[u]) cnt[c[adj[u][i]]]++;
        if (u != 1) cnt[c[1] ^ c[u]]++;
        if (cnt[1] == 0 || (cnt[1] >= 2)) {
            puts("First");
            return 0;
        }
    }
    puts("Second");
    return 0;
}
