#include <iostream>
#include <vector>
using namespace std;//DFS

const int nmax = 8;
bool graph[nmax][nmax];//globalで持つ　→　関数内で使える

int dfs (int now, int n, vector<bool> visited) {
    bool all_visited = true;
    for (int i=0; i<n; i++) {
        if (visited[i] == false) all_visited = false;
    }
    if (all_visited) return 1;
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (graph[now][i] == false) continue;
        if (visited[i]) continue;
        visited[i] = true;
        sum += dfs(i, n, visited);
        visited[i] = false;
    }
    return sum;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a][b] = graph[b][a] = true;
    }
    vector<bool> visited(n, false);
    visited[0] = true;
    cout << dfs(0, n, visited) << endl;
}