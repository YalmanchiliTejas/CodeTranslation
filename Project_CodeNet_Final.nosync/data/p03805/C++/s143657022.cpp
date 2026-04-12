#include <iostream>
 
using namespace std;

int n, m;
bool path[8][8];
 
int dfs(int c, bool visited[]) {
    bool allVisited = true;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            allVisited = false;
        }
    }

    if (allVisited) {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (path[c][i] && !visited[i]) {
            visited[i] = true;
            ans += dfs(i, visited);
            visited[i] = false;
        }
    }
    return ans;
}
 
int main() {
    cin >> n >> m;
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        path[a-1][b-1] = path[b-1][a-1] = true;
    }

    bool visited[8];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    visited[0] = true;
  
    cout << dfs(0, visited) << endl;
}
