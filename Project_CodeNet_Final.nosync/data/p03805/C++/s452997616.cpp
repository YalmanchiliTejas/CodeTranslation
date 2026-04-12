#include <iostream>
#include <vector>

using namespace std;

int ans;
bool visited[8];
bool all_visited;
vector<int> G[8];

void dfs(int cur, int n) {
    visited[cur] = true;
    all_visited = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            all_visited = false;
            break;
        }
    }
    if (all_visited) { ans++; }
    for (auto e: G[cur]) {
        if (!visited[e]) {
            dfs(e, n);
            visited[e] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    dfs(0, n);

    cout << ans << endl;

    return 0;
}
