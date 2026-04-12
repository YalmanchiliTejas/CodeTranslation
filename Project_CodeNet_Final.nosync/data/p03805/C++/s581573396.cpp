#include <iostream>
#include <vector>
#include <string>

#define rep(i, cc, n) for (int i = cc; i < n; ++i)

using namespace std;

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax])
{
    bool all_visited = true;

    rep(i, 0, N)
    {
        if (visited[i] == false)
            all_visited = false;
    }

    if (all_visited)
    {
        return 1;
    }
    int ret = 0;
    rep(i, 0, N)
    {
        if (graph[v][i] == false)
        {
            continue;
        }
        if (visited[i])
        {
            continue;
        }

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }

    return ret;
}
int main()
{
    int N, M;
    cin >> N >> M;
    rep(i, 0, M)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        graph[A][B] = graph[B][A] = true;
    }

    bool visited[nmax];
    rep(i, 0, N)
    {
        visited[i] = false;
    }

    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
    return 0;
}