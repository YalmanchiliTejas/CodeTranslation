#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;

using Graph = V<V<int>>;
Graph g;
V<bool> seen;
int n, m;
int ans = 0, cnt = 0;

void dfs(int v) {
    // 最後の頂点以外がtrueであれば答え加算して戻る
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (!seen[i] && i != v) {
            ok = false;
            break;
        }
    }
    if (ok) {
        ans++;
        return;
    }

    seen[v] = true;
    for (auto next_v : g[v]) {
        if (seen[next_v]) continue;
        dfs(next_v);
    }
    // 頂点をfalseに戻す=順番にfalseに戻っていくので、
    // スタートからまた別経路を試せる=経路全探索できる
    seen[v] = false;
}

int main() {
    cin >> n >> m;

    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    seen.resize(n);
    for (int i = 0; i < n; i++) seen[i] = false;
    dfs(0);
    cout << ans << endl;

    return 0;
}
