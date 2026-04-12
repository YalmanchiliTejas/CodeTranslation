#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int n, m;
vector<vector<int>> g;
int ans = 0;

void dfs(int v, vector<bool> seen) {
    bool end = true;
    for (int i = 0; i < seen.size(); ++i) {
        if (!seen[i] && i != v) end = false; //入力のv以外で見ていないところがあるか
    }

    if (end) {
        ++ans;
        return;
    }

    for (auto nv : g[v]) {
        if (seen[nv]) continue;

        seen[nv] = true;
        dfs(nv, seen);
        seen[nv] = false;
    }
}

int main() {

    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> seen(n, false);

    seen[0] = true;
    dfs(0, seen);

    cout << ans << endl;
}