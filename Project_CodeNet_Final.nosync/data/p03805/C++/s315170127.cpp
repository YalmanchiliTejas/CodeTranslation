// ABC 007 C

#include<bits/stdc++.h>
using namespace std;
#define ll long long
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int ret = 0;
void dfs(const Graph &G, int v, vector<bool> visited) {
    if (adjacent_find(visited.begin(), visited.end(), not_equal_to<>()) == visited.end()) {
        ret++;
    }

    for (auto next_v : G[v]) { 
        if (visited[next_v] == false) {
            visited[next_v] = true;
            dfs(G, next_v, visited);
            visited[next_v] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> visited;
    visited.assign(n, false);
    visited[0] = true;
    dfs(G, 0, visited);

    cout << ret << endl;
    return 0;
}