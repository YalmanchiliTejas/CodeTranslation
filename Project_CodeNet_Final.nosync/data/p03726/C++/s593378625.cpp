#include <iostream>
#include <set>
using namespace std;

const int N = 100 * 1000 + 10;

int n;
int q[N], L, R; // <- queue
set <int> adj[N];

void input() {
    cin.tie(0);
    cin >> n;

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;

        adj[v].insert(u);
        adj[u].insert(v);
    }
    return;
}

void solve() {
    if (n % 2 == 1) {
        cout << "First";
        return;
    }

    for (int i = 0; i < n; i++)
        if (adj[i].size() == 1)
            q[R++] = i;

    while (L < R) {
        int v = q[L++], par = *(adj[v].begin());
        if (adj[v].empty())
            continue;

        for (auto u : adj[par]) {
            adj[u].erase(par);

            if (adj[u].size() == 1)
                q[R++] = u;
            else if (u != v && adj[u].size() == 0) {
                cout << "First";
                return;
            }
        }
        adj[par].clear();
    }

    cout << "Second";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}
