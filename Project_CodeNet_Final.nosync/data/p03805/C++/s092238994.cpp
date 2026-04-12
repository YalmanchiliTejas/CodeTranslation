#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Graph {
    enum Color {WHITE, GRAY, BLACK};
    vector<vector<int>> adj;
    vector<Color> color;
    Graph(int n) {
        adj.assign(n, vector<int>());
        color.assign(n, WHITE);
    }
};

int dfs(Graph& g, int u)
{
    bool completed = true;
    for (auto c : g.color) {
        if (c == Graph::WHITE) {
            completed = false;
            break;
        }
    }
    if (completed) {
        return 1;
    }
    int ans = 0;
    for (auto v : g.adj[u]) {
        if (g.color[v] == Graph::WHITE) {
            g.color[v] = Graph::BLACK;
            ans += dfs(g, v);
            g.color[v] = Graph::WHITE;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.adj[a - 1].push_back(b - 1);
        g.adj[b - 1].push_back(a - 1);
    }

    g.color[0] = Graph::BLACK;
    cout << dfs(g, 0) << endl;
}