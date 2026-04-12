//in the name of <Allah>
#include <bits/stdc++.h>
using namespace std;

const int N = 1 * 100 * 1000 + 1;
int n, sz[N];
vector <int> adj[N];

bool dfs(int u, int par) {
    int odd = 0, res = 0;
    sz[u] = 1;
    for (auto v: adj[u])
        if (v ^ par) {
            res |= dfs(v, u);
            sz[u] += sz[v];
            odd += (sz[v] & 1);
        }
    return (res | (odd > 1));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }   
    if (n & 1 || dfs(0, -1))
        return cout << "First\n", 0;
    cout << "Second\n";
}
