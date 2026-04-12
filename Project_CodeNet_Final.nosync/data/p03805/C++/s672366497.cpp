#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool graph[8][8] = { false };

bool is_all_visited(int n, bool visited[]) {
        for (int i = 0; i < n; i++)
                if (visited[i] == false)
                        return false;
        return true;
}

int dfs(int v, int n, bool visited[]) {
        if (is_all_visited(n, visited))
                return 1;

        int ret = 0;

        for (int i = 0; i < n; i++) {
                if (graph[v][i] == false)
                        continue;
                if (visited[i])
                        continue;

                visited[i] = true;
                ret += dfs(i, n, visited);
                visited[i] = false;
        }

        return ret;
}

int main() {
        int n, m, a, b;

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
                cin >> a >> b;
                a--; b--;
                graph[a][b] = graph[b][a] = true;
        }

        bool visited[8] = { false };
        visited[0] = true;
        cout << dfs(0, n, visited) << endl;

        return 0;
}
