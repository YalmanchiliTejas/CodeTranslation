#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

int main() {
#ifdef BZ
    freopen("in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int a = 1; a <= n; a++) {
        int l = k, r = a - 1;
        if (l > r) continue;
        while (l <= n) {
            int cl = l, cr = r;
            cl = max(1, cl);
            cr = min(n, cr);
            ans += cr - cl + 1;
            l += a;
            r += a;
        }
    }
    cout << ans << endl;
}