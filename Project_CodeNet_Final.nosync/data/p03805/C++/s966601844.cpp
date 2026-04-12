#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric> 
#include <math.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define INF 999999999
using namespace std;

bool graph[8][8];

int dfs(int v, int n, bool visited[8]) {
    bool all_visited = true;

    REP(i, n) {
        if(visited[i] == false) {
            all_visited = false;
        }
    }

    if(all_visited) return 1;

    int ret = 0;
    REP(i, n) {
        if(graph[v][i] == false) continue; //no edge
        if(visited[i]) continue; // already

        visited[i] = true;
        ret += dfs(i, n, visited);
        visited[i] = false;
    }

    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;

    REP(i, m) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }

    bool visited[8];
    REP(i, n) {
        visited[i] = false;
    }

    visited[0] = true;
    cout << dfs(0, n, visited) << endl;
    return 0;
}
