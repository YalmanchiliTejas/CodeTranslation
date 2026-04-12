// プリム法 最小全域木 Minimum Spanning Tree
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
static const int MAX = 100;
static const int INF = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]) {

    bool all_visited = true;

    for(int i = 0; i < N; i++) {
        if (visited[i] == false) {
            all_visited = false;
        }
    }

    if (all_visited) {
        return 1;
    }

    int ret = 0;

    for(int i = 0; i < N; i++) {
        if (graph[v][i] == false) continue;
        if (visited[i]) continue;

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }

    return ret;
}

int main() {

    int n ,m;
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }

    bool visited[nmax];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[0] = true;
    cout << dfs(0, n, visited) << endl;
    
    return 0;
}