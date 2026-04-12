/***********************************************
#
#      Filename: d.cpp
#
#        Author: Comsyl - ylsong15@fudan.edu.cn
#   Description: ---
#        Create: 2017-05-11 19:41:07
***********************************************/
#include <bits/stdc++.h>
using namespace std;
bool ok;

// whether cur needs to match par
int dfs(int cur, int par, const vector<vector<int>>& E) {
    int cnt = 0;
    for (int v : E[cur]) {
        if (v != par) {
            cnt += dfs(v, cur, E);
        }
    }
    if (cnt > 1) {
        ok = false;
        return 0;
    }
    if (cnt == 1) return 0;
    return 1;
}

int main()
{
    int n;
    cin >> n;
    auto E = vector<vector<int>> (n, vector<int>());
    int u, v;
    for (int i = 0; i < n-1; ++ i) {
        cin >> u >> v;
        -- u; -- v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    ok = true;
    int res = dfs(0, -1, E);
    if (ok) ok = (res == 0);
    cout << (ok ? "Second" : "First") << endl;
    return 0;
}
