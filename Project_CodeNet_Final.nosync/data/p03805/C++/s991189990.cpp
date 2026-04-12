#include <bits/stdc++.h>
using namespace std;
const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax])
{
/**
 * @param v 探索開始頂点
 * @param N 頂点数
 * @param visited 訪問済みの頂点の配列
 */
    bool all_visited = true;

    for (int i = 0; i < N; i++)
    {
        if(visited[i] == false)
        {
            all_visited = false;
        }
    }
    if(all_visited)
    {
        return 1;
    }

    int ret = 0;

    for (int i = 0; i < N; i++)
    {
        if(graph[v][i]==false) continue;    //graph[v][i]が未接続ならpass
        if(visited[i]) continue;            //頂点iが訪問済みならpass

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }
    
    return ret;
    
}

int main(void)
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A-1][B-1] = graph[B-1][A-1] = true;   //無向グラフのため 例：3<-->4
    }

    bool visited[nmax];
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;     //全ての頂点は未訪問
    }

    visited[0] = true;      //頂点1は訪問済み
    cout << dfs(0, N, visited) << endl;
}