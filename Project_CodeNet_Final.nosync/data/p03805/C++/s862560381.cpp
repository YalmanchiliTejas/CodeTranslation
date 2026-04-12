#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<bool>> way, vector<bool> visited, int dep) {
    int ret = 0;
    bool all_visited = true;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == false) all_visited = false;
    }

    if (all_visited) return 1;

    for (int i = 0; i < way.size(); i++) {
        if (way[dep][i] == false) continue;
        if (visited[i] == true) continue;
        visited[i] = true;
        ret += dfs(way, visited, i);
        visited[i] = false;
    }

    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> way(n, vector<bool>(n, false));
    vector<bool> visited(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        way[a - 1][b - 1] = way[b - 1][a - 1] = true;
    }
    visited[0] = true;
    cout << dfs(way, visited, 0) << endl;

    return 0;
}