#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool ans = false;
    function<int(int, int)> dfs = [&] (int v, int p) {
        int up = 0;
        for(auto to : g[v]) {
            if(to == p) continue;
            up += dfs(to, v);
        }
        if(up >= 2) ans = true;
        return !up;
    };
    ans |= dfs(0, -1) != 0;

    cout << (ans ? "First" : "Second") << endl;
}
