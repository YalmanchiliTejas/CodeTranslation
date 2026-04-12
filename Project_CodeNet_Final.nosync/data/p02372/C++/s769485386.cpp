#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

vector<pair<int, int>> g[maxn];

int in[maxn], out[maxn];

void dfs1(int u, int p = -1) {
    for (auto x : g[u]) {
        if (x.first == p)continue;
        dfs1(x.first, u);
        in[u] = max(in[u], x.second + in[x.first]);
    }
}

void dfs2(int u, int p = -1) {
    int mx1(-1), mx2(-1);
    for (auto x :g[u]) {
        if (x.first == p)continue;
        if (in[x.first] + x.second >= mx1)mx2 = mx1, mx1 = in[x.first] + x.second;
        else if (in[x.first] + x.second > mx2)mx2 = in[x.first] + x.second;
    }
    for (auto x :g[u]) {
        if (x.first == p)continue;
        int use = mx1;
        if (in[x.first] + x.second == mx1)
            use = mx2;
        out[x.first] = max(x.second + use, x.second + out[u]);
        dfs2(x.first, u);
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;

        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dfs1(0);
    dfs2(0);
    for (int i = 0; i < n; i++)
        cout << max(in[i], out[i]) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}
