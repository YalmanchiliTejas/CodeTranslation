#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL n, x, m;

LL fp(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
const int N = 1e5 + 3;
int p[N];
LL a[10 * N];
LL s[10 * N];
#include <cstring>
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


    cin >> n >> x >> m;
    a[1] = s[1] = x;
    memset(p, -1, sizeof p);
    LL ans = 0;
    ans = x;
    for (int i = 2; i <= n; i++) {
        if (i > 10 * N) throw;
        a[i] = a[i - 1] * a[i - 1] % m;
        s[i] = a[i] + s[i - 1];
        if (~p[a[i]]) {
            int l = i - p[a[i]];
            LL x = n - i + 1;
            LL t = x / l;
            LL sl = s[i - 1] - s[p[a[i]] - 1];
            LL r = x % l;
            ans += sl * t;
            ans += s[p[a[i]] + r - 1] - s[p[a[i]] - 1];
            cout << ans << endl;
            return 0;
        }
        p[a[i]] = i;
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}