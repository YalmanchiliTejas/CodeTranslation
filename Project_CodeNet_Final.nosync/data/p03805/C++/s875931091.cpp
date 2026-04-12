#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()
#define mod 1000000007
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    bool g[n][n] = {};
    rep(i, 0, m) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        g[a[i]][b[i]] = true;
        g[b[i]][a[i]] = true;
    }

    int path[n];
    rep(i, 0, n) path[i] = i;
    int ans = 0;
    do {
        if (path[0] != 0) continue;
        bool flag = true;
        rep(i, 0, n - 1) if (!g[path[i]][path[i + 1]]) flag = false;
        if (flag) ans++;
    } while (next_permutation(path, path + n));

    cout << ans << endl;
    return 0;
}
