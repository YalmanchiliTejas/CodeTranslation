#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
bool can;

int dfs(const Graph &G, int v, vector<bool> &seen)
{
    bool can = true;
    for (auto t : seen)
    {
        if (!t)
            can = false;
    }
    if (can)
        return 1;

    int ans = 0;
    for (auto t : G[v])
    {
        if (seen[t])
            continue;
        seen[t] = true;
        ans += dfs(G, t, seen);
        seen[t] = false;
    }
    return ans;
}

int main()
{
    int n, m; //頂点、辺
    cin >> n >> m;
    Graph G(n);
    vector<bool> seen(n, false);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    seen[0] = true;

    cout << dfs(G, 0, seen) << endl;
}