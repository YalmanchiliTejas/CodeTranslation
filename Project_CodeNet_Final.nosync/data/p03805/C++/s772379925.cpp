#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
int cnt = 0;
vector<bool> seen;

void dfs (int now) {
    for (int next: graph[now]) {
        if (seen[next]) continue;
        else {
            seen[next] = true;
            dfs(next);
            seen[next] = false;
        }
    }
    bool all_seen = true;
    for (int i=0; i<n; ++i) {
        if (!seen[i]) all_seen = false;
    }
    if (all_seen) cnt++;
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    seen.resize(n);
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    seen[0] = true;
    dfs(0);
    cout << cnt << endl;
}