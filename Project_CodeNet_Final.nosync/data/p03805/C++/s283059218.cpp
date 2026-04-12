#include <bits/stdc++.h>
using namespace std;

const int max_n = 8 + 1;
bool edge[max_n][max_n];
int n, m;

int dfs(int v, bool visited[max_n])
{
    bool visited_all = true;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited_all = false;
        }
    }
    if (visited_all)
    {
        return 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && edge[v][i])
        {
            visited[i] = true;
            cnt += dfs(i, visited);
            visited[i] = false;
        }
    }
    return cnt;
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a][b] = true;
        edge[b][a] = true;
    }

    bool visited[max_n];
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    visited[1] = true;

    cout << dfs(1, visited) << endl;
}