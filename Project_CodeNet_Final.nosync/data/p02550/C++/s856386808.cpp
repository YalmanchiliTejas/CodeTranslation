#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n, x, m;
int vis[N] = {};
long long ans[N] = {};
int main() {
    cin >> n >> x >> m;
    x %= m;
    ans[1] = x;
    vis[x] = 1;
    int r = -1, d;
    for (int i = 2; i <= n; i++) {
        x = x * x % m;
        ans[i] = ans[i - 1] + x;
        if (vis[x]) {
            r = vis[x];
            d = i - vis[x];
            break;
        }
        vis[x] = i;
    }
    if (r == -1) cout << ans[n] << '\n';
    else {
        long long f = (n - r) / d, rr = (n - r) % d;
        cout << ans[r + rr] + (ans[r + d] - ans[r]) * f << '\n';
    }
    return 0;
}