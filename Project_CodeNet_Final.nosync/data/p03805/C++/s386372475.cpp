#include <bits/stdc++.h>

int dfs(int, std::vector<bool>, int);
int n, m;
std::list<int> edges[8];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    std::vector<bool> visited(8);
    std::fill(visited.begin(), visited.end(), false);
    printf("%d\n", dfs(0, visited, 0));

    return 0;
}


int dfs(int pos, std::vector<bool> visited, int visited_num)
{
    if (visited[pos]) return 0;
    if (visited_num == n - 1) return 1;
    visited[pos] = true;
    int count{};
    for (auto &e : edges[pos])
    {
        count += dfs(e, visited, visited_num + 1);
    }
    return count;
}
