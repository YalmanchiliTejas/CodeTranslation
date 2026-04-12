#include <iostream>

using namespace std;

const int NMAX = 9;
bool visited[NMAX], graph[NMAX][NMAX];
int n, m, ans;

void dfs(int currentNode, int numVisited) {
    if (numVisited == n) {
        ans++;
    }

    visited[currentNode] = true;
    for (int i = 1; i <= n; i++) {
        if (graph[currentNode][i] && !visited[i]) {
            dfs(i, numVisited + 1);
        }
    }
    visited[currentNode] = false;
}

int main() {
    cin >> n >> m;

    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
    }

    dfs(1, 1);

    cout << ans << endl;
}
