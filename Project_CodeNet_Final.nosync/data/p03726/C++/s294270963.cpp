#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    if (n % 2 == 1) {
        cout << "First" << '\n';
        return 0;
    }
    vector<int> was(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
        }
        if (!was[v]) {
            was[v] = 1;
            if (p == -1 || was[p]) {
                cout << "First" << '\n';
                exit(0);
            } else {
                was[p] = 1;
            }
        }
    };
    dfs(0, -1);
    cout << "Second" << '\n';
    return 0;
}
