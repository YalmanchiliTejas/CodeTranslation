#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
#define INF 99999999
typedef std::pair<int,int> pii;
const int nmax = 8;
bool graph[nmax][nmax];
int dfs(int v, int N, bool g[nmax]) {
    bool all = true;
    for (int i = 0; i < N; i++) {
        if (!g[i]) {
            all = false;
        }
    }
    if (all) {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (!graph[v][i]) continue;
        if (g[i]) continue;
        g[i] = true;
        res += dfs(i, N, g);
        g[i] = false;
    }
    return res;
}
int main(){
    int N,M;
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
    }
    bool visited[nmax];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    visited[0] = true;
    std::cout << dfs(0, N, visited) << std::endl;
    return 0;
}