#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<vector<int> > g(8);
bool visited[8];
int dfs(int cur, bool visited[8]) {
    ll ans = 0;
    bool all_visited = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            all_visited = false;
        }
    }

    if (all_visited) {
        return 1;
    }
    for (int i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i];
        if (!visited[next]) {
            visited[next] = true;
            ans += dfs(next, visited);
            visited[next] = false;
        }
    }

    return ans;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    visited[0] = true;
    ll ans = dfs(0, visited);


    cout << ans << endl;


    return 0;
}
