#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long ll;
#define INF 1e9

using namespace std;
const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int n, bool visited[nmax]){
    bool all_visited = true;

    for (int i = 0; i < n; i++){
        if(visited[i] == false)
        all_visited = false;
    }

    //辺を全部通ったら1を返す
    if(all_visited == true) return 1;

    int ret = 0;//回数
    for (int i = 0; i < n; i++){
        if(graph[v][i] == false) continue;//辺訪問済み
        if(visited[i]) continue; //点訪問済み

        visited[i] = true;
        ret += dfs(i, n, visited);
        visited[i] = false;//訪問前に再設定
    }
    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
    }

    bool visited[nmax];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }

    visited[0] = true; //出発点

    cout << dfs(0, n, visited) << endl;
    return 0;
}