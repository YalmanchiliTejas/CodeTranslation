#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

vector<vector<int> > graph;
bool res = true;
bool used[N];

void dfs(int v, int par) {
    for (int u : graph[v]) {
        if (u == par)
            continue;
        dfs(u, v);
    }
    if (!used[v]) {
        if (par == v || used[par])
            res = false;
        used[par] = true;
        used[v] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, 0);
    if (res) {
        cout << "Second\n";
    } else {
        cout << "First\n";
    }
    return 0;
}
