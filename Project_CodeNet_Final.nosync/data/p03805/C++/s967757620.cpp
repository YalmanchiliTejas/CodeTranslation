#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges(N, vector<int>());
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    stack<pair<int, int>> dfs;
    int count = 0;
    dfs.emplace(0, 1);
    while (!dfs.empty())
    {
        auto d = dfs.top();
        dfs.pop();
        auto current = d.first;
        auto visited = d.second;
        if (visited == pow(2, N) - 1)
        {
            count++;
            continue;
        }
        for (auto target : edges[current])
        {
            if (visited & 1 << target)
            {
                continue;
            }
            dfs.emplace(target, visited | 1 << target);
        }
    }
    cout << count  << endl;
}