#include <iostream>

#define VERTEX 10

int  N, M;
bool adj[VERTEX][VERTEX] = { false };
bool visited[VERTEX]     = { false };

long dfs(int v) {
    long ans = 0;
    bool all_visited = true;
    for (int i=0; i<N; ++i) {
        if (visited[i] == false) all_visited = false;
    }
    if (all_visited) return 1;

    for (int i=0; i<N; ++i) {
        if ( adj[v][i] && visited[i] == false ) {
            visited[i] = true;
            ans += dfs(i);
            visited[i] = false;
        }
    }
    return ans;
}

void solve() {
    long ans = 0;
    visited[0] = true;
    std::cout << dfs(0) << std::endl;
}

int main() {
    std::cin >> N >> M;
    for (int i=0; i<M; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        adj[u][v] = true;
        adj[v][u] = true;
    }
    solve();
    return 0;
}