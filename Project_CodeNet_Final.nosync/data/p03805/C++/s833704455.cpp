#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, m;
    cin >> n >> m;

    int g[10][10] = {};
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;

        g[a][b] = 1;
        g[b][a] = 1;
    }

    vector<int> p;
    for (int i = 1; i < n; ++i) {
        p.push_back(i);
    }

    int ans = 0;

    do {
        bool ok = true;
        if (g[0][p[0]] == 0) ok = false;

        for (int i = 1; i < n - 1; ++i) {
            if (g[p[i-1]][p[i]] == 0) {
                ok = false;
                break;
            }
        }

        if (ok) ans++;
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;
}