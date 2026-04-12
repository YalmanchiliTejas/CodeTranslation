#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, m, a, b, g[8][8] = {}, p[8];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        p[i] = i;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        g[a][b] = g[b][a] = 1;
    }

    int ans = 0;
    do {
        bool f = true;
        for (int i = 0; i < n - 1; ++i) {
            if (g[p[i]][p[i + 1]] == 0)
                f = false;
        }
        if (f)
            ans++;
    } while(next_permutation(p + 1, p + n));

    cout << ans << endl;

    return 0;
}