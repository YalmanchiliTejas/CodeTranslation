#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using Graph = vector<vector<int> >;
Graph G;

void dfs(int v, vector<bool> &seen, int &res) {
    bool end = true;
    rep(i,seen.size()) if(!seen[i] && i!=v) end = false;
    if (end) {
        ++res;
        return;
    }

    seen[v] = true;
    for (auto nv : G[v]) {
        if (seen[nv]) continue;
        dfs(nv, seen, res);
    }
    seen[v] = false;
}

int main() {
    int N, M; cin >> N >> M;
    G.assign(N, vector<int>());
    rep (i,M) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> seen(N, false);
    int res = 0;
    dfs(0, seen, res);
    cout << res << endl;
}