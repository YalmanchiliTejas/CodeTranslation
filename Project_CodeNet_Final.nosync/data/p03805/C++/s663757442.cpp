#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int nmax = 8;

bool graph[nmax][nmax];  //グラフの隣接行列

int dfs(int v, int N, bool visited[nmax]) {  // vはdfsを開始する頂点、Nはグラフの頂点数
    
    bool all_visited = true;  //全ての頂点を訪れたかどうか

    //未訪問の頂点があればall_visitedはfalse
    rep(i, N) {
        if(!visited[i]) {
            all_visited = false;
        }
    }

    //すべての頂点を訪れている場合は1を返す
    if(all_visited) {
        return 1;
    }

    int ret = 0;
    //頂点vに隣接する未訪問の頂点を全探索
    rep(i, N) {
        //vと隣接していなかったらダメ
        if(!graph[v][i]) {
            continue;
        }
        //訪問済みだったらダメ
        if(visited[i]) {
            continue;
        }
        //頂点iを訪問済みにする
        visited[i] = true;

        ret += dfs(i, N, visited);
        visited[i] = false;
    }

    return ret;
}

int main() {
    int n;  //頂点数
    int m;  //辺数
    cin >> n >> m;

    //無向グラフの入力
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }

    bool visited[nmax];  // visited[i] : 頂点iを訪問したかどうか
    //全頂点を未訪問にする
    rep(i, n) {
        visited[i] = false;
    }
    //スタート位置の頂点0を訪問済みにする
    visited[0] = true;

    cout << dfs(0, n, visited) << endl;
    return 0;
}