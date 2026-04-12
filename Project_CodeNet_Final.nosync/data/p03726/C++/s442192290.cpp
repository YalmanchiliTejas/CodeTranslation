#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
vector < int > g[maxN];
int n;
bool dfs(int v, int p) {
    bool has = true;
    for (int to : g[v]) {
        if (to == p) continue;
        if (dfs(to, v)) {
            if (!has) {
                cout << "First";
                exit(0);
            }
            has = false;
        }
    }
    return has;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (!dfs(1, -1)) {
        cout << "Second";
    }
    else {
        cout << "First";
    }
    return 0;
}