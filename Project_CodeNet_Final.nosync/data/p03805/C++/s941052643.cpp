#include <bits/stdc++.h>

using namespace std;

const int nmax = 8;

int ans, n, m;
vector<vector<int>> g(nmax);

void dfs(int u, int mask)
{
    if (mask == (1 << n) - 1)
        ans++;
    for (int v : g[u])
        if (!((1 << v) & mask))
            dfs(v, mask | (1 << v));
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    ans = 0;
    dfs(0, 1);
    cout << ans << "\n";
    return 0;
}