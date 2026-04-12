#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = true;
        g[b][a]= true;
    }

    int ans = 0;
    vector<int> ver(n);
    iota(ver.begin(), ver.end(), 0);
    while (true) {
        bool ok = true;
        for (int i = 0; i + 1 < n; i++) {
            ok &= g[ver[i]][ver[i + 1]];
        }
        if (ok) ans++;
        if (not next_permutation(ver.begin() + 1, ver.end())) break;
    }

    cout << ans << '\n';

    return 0;
}