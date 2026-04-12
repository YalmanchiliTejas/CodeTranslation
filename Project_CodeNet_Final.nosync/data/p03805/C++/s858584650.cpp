#define _CRT_SECURE_NO_WARNINGS
#include <array>
#include <cstdio>

using namespace std;

const int nmax = 8;
array<array<bool, nmax>, nmax> graph;

int dfs(int v, int N, bool visited[nmax])
{
    bool all_visited = true;

    for (int i = 0; i < N; i++) if (visited[i] == false) all_visited = false;

    if (all_visited) return 1;

    int ret = 0;

    for(int i = 0; i < N; i++)
    {
        if (graph[v][i] == false) continue;
        if (visited[i]) continue;

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }

    return ret;
}

int main(void)
{
    int N, M;
    if (scanf("%d%d", &N, &M) < 2) return 0;

    for(int i=0; i < M; i++)
    {
        int A, B;
        if (scanf("%d%d", &A, &B) < 2) return 0;

        A--;
        B--;
        graph[A][B] = graph[B][A] = true;
    }

    bool visited[nmax];
    for(int i = 0; i < N; i++) visited[i] = false;

    visited[0] = true;
    printf("%d\n", dfs(0, N, visited));
    return 0;
}
