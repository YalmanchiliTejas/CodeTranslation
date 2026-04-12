#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <bitset>
#include <map>
#include <climits>
#include <set>
#include <cmath>

using namespace std;

static const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int N, vector<int> &visited)
{
    bool all_visited = count(visited.begin(), visited.end(), 1) == visited.size();
    if (all_visited)
    {
        return true;
    }
    int ret = 0;
    for (int i = 0; i < N; ++i)
    {
        if (graph[v][i] == false)
        {
            continue;
        }
        if (visited[i])
        {
            continue;
        }

        // 探索ごとにvisitedがあるのが大事だなー
        auto copy_visited = visited;
        copy_visited[i] = true;
        ret += dfs(i, N, copy_visited);
    }
    return ret;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    vector<int> visited(N, 0);
    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
    return 0;
}