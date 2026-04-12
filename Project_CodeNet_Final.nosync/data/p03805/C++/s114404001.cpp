#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

using Graph = vv<int>;
v<bool> seen;

int dfs(const Graph &G, int v)
{
    seen[v] = true;
    bool all = true;

    for (int i = 0; i < seen.size(); i++)
    {
        if (!seen[i])
            all = false;
    }

    if (all)
        return 1;

    
    int ans = 0;
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        ans += dfs(G, next_v);
        seen[next_v] = false;
    }
    return ans;
}

int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);

    cout << dfs(G, 0) << endl;

    return 0;
}