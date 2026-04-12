// 再帰関数
// dfs 深さ優先探索
// Nx0の2次元配列
//  https://atcoder.jp/contests/apg4b/tasks/APG4b_t
// 重み無し無向グラフ
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int const nmax = 8;
bool visited[nmax];
using Graph = vector<vector<int>>;

int dfs(int v, int N, Graph g)
{
    bool all_visited = true;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == false)
            all_visited = false;
    }
    if (all_visited)
    {
        //       cout << "all visited,v=" << v << endl;
        return 1;
    }

    int ret = 0;
    for (auto i : g[v])
    {
        //        cout << "v=" << v << ",i=" << i << endl;
        //     cout << "ret=" << ret << endl;
        if (visited[i] == true)
        {
            //       cout << "i=" << i << " was visited" << endl;
            continue;
        }
        visited[i] = true;
        ret += dfs(i, N, g);
        visited[i] = false;
    }
    return ret;
}

int main()
{
    int N, M;
    cin >> N >> M;
    Graph g(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < N; i++)
        visited[i] = false;

    visited[0] = true;
    cout << dfs(0, N, g) << endl;
}