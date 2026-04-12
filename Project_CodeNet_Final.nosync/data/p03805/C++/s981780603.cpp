#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a][b] = g[b][a] = true;
    }

    vector<int> c(n);
    iota(c.begin(), c.end(), 0);
    int ans = 0;
    do {
        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            if (!g[c[i]][c[i + 1]]) flag = false;
        }
        if (flag) ans++;
    } while (next_permutation(c.begin() + 1, c.end()));
    cout << ans << endl;
    return 0;
}
