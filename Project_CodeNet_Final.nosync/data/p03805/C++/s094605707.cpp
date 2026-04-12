#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u][v] = g[v][u] = true;
    }

    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        v[i] = i + 1;
    }
    int ans = 0;
    do
    {
        int p = 0;
        bool ok = true;
        for (auto& i : v) {
            ok &= g[p][i];
            p = i;
        }
        if (ok) ++ans;

    } while (next_permutation(v.begin(), v.end()));
    cout << ans << '\n';

    return 0;
}
