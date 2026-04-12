#include <bits/stdc++.h>
using namespace std;

int N, M, ans, cnt, a, b;

vector<vector<int>> G;
vector<bool> visited;

void dfs(int now)
{
    visited[now] = true, cnt++;
    ans += cnt == N;
    for (int i = 0; i < G[now].size(); i++)
    {
        int next = G[now][i];
        if (visited[next] == false)
            dfs(next);
    }
    visited[now] = false, cnt--;
}

int main()
{
    cin >> N >> M;
    G = vector<vector<int>>(N);
    visited = vector<bool>(N, false);
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0);
    cout << ans << endl;
}