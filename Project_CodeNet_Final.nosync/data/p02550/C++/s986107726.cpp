#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, x, m, stp, now, a, b, len, pos;
int vis[N];
int res[N];
signed main () {
    cin >> n >> x >> m;
    now = x;
    while (1) {
        if (vis[now]) {
            // cout << now << " " << vis[now] <<endl;
            // for (int i = 1; i <= stp; i++) cout << res[i] <<endl;
            for (int i = vis[now]; i <= stp; i++) b += res[i];
            for (int i = 1; i <= vis[now] - 1; i++) a += res[i];
            len = stp - vis[now] + 1;
            n -= vis[now] - 1; pos = vis[now];
            break;
        }
        res[++stp] = now;
        vis[now] = stp;
        now = now * now % m;
    }
    // cout << a << " " << b << " " << n << " " <<len << endl;
    int ans = a + b * (n / len);
    for (int i = 0; i <= (n % len) - 1; i++) ans += res[i + pos];
    printf ("%lld\n", ans);
    return 0;
}
