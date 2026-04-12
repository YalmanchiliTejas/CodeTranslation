#include<bits/stdc++.h>

using namespace std;
const int Nmax = 1e5 + 100;

int n, avail[Nmax], ass[Nmax], t, res;
vector<int> a[Nmax];

bool visit(int u) {
    if (avail[u] != t) avail[u] = t;
    else return false;
    for(int i = 0; i < (int)a[u].size(); ++i) {
        int v = a[u][i];
        if (!ass[v] || visit(ass[v])) {
            ass[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) {
        ++t;
        res += visit(i);
    }
    cout << (res == n ? "Second" : "First");
}
