#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 * 1000 + 10;
int n, sz[maxn];
vector <int> adj[maxn];
bool ans;

void dfs(int v, int papa) {
    if (ans)
        return;
    sz[v] = 1;
    int o = 0, tmp = 0;
    bool f = 1;
    for (int u: adj[v])
        if (u != papa) {
            dfs(u, v);
            sz[v] += sz[u];
            o += (sz[u] % 2);
        }
    if (o > 1)
        ans = 1;
}

int main() {
    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << (((n % 2) || ans)? "First\n": "Second\n");
    return 0;
}