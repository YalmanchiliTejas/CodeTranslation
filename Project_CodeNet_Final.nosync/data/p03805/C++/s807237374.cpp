#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;

Graph g;

void dfs(int v, vector<bool> &seen, int &res) {
    bool end = true;
    rep(i, seen.size()) if(!seen[i] && i != v) end = false;
    if(end) {
        res++;
        return;
    }

    seen[v] = true;
    for(auto next : g[v]) {
        if(seen[next]) continue;
        dfs(next, seen, res);
    }
    seen[v] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> seen(n, false);
    int res = 0;
    dfs(0, seen, res);

    cout << res << endl;

    return 0;
}