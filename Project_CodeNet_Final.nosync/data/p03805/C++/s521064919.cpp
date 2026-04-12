#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> G[8];

int dfs(int v, bool visited_vertexes[8])
{
    bool flag = true;
    for (int i = 0; i < N; ++i)
    {
        if (!visited_vertexes[i])
            flag = false;
    }

    if (flag)
        return 1;

    int res = 0;
    for (int i = 0; i < G[v].size(); ++i)
    {
        if (visited_vertexes[G[v][i]])
            continue;
        visited_vertexes[G[v][i]] = true;
        res += dfs(G[v][i], visited_vertexes);
        visited_vertexes[G[v][i]] = false;
    }

    return res;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool visited_vertexes[8] = {false};
    visited_vertexes[0] = true;

    cout << dfs(0, visited_vertexes) << endl;
}