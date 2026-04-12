#include <bits/stdc++.h>
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define _GLIBCXX_DEBUG
using namespace std;

int dfs(int start, map<int, vector<int>> graph, set<int> visited, int N)
{

    // add to visited
    visited.insert(start);

    // base case
    if (visited.size() == N)
    {
        return 1;
    }

    // recursive

    int result = 0;
    for (int i : graph[start])
    {
        if (!visited.count(i))
        {
            result += dfs(i, graph, visited, N);
        }
    }

    return result;
}

int main()
{
    int N, M;
    cin >> N >> M;
    map<int, vector<int>> graph;

    // init connected list
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        if (!graph.count(a))
        {
            graph[a] = {};
        }
        graph[a].push_back(b);

        if (!graph.count(b))
        {
            graph[b] = {};
        }
        graph[b].push_back(a);
    }

    cout << dfs(1, graph, {}, N) << endl;
}
