#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int N, M, ans, cnt;

vector<vector<int>> G;
vector<bool> visited;

void dfs(int now)
{
    visited[now] = true;
    cnt++;
    if (cnt == N)
    {
        ans++;
    }
    for (int i = 0; i < G[now].size(); i++)
    {
        int next = G[now][i];
        if (visited[next] == false)
            dfs(next);
    }
    visited[now] = false;
    cnt--;
}

int main()
{
    cin >> N >> M;
    G = vector<vector<int>>(N);
    visited = vector<bool>(N, false);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        //cout << a << " " << b << endl;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0);
    cout << ans << endl;
}