#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int n, s, a[3003];

ll sol(int l, int r) {
    ll z = 0;
    int d[3003] = {1}, e[3003] = {}, f[3003] = {1}, g[3003] = {};
    if (l == r) return a[l] == s;
    int m = (l + r) / 2;
    for (int i = m; i >= l; i--) {
        for (int j = s; j >= a[i]; j--) {
            d[j] += d[j - a[i]];
            if (d[j] >= 998244353) d[j] -= 998244353;
        }
        for (int j = 0; j <= s; j++) {
            e[j] += d[j];
            if (e[j] >= 998244353) e[j] -= 998244353;
        }
    }
    for (int i = m + 1; i <= r; i++) {
        for (int j = s; j >= a[i]; j--) {
            f[j] += f[j - a[i]];
            if (f[j] >= 998244353) f[j] -= 998244353;
        }
        for (int j = 0; j <= s; j++) {
            g[j] += f[j];
            if (g[j] >= 998244353) g[j] -= 998244353;
        }
    }
    for (int i = 0; i <= s; i++) z = (z + 1ll * e[i] * g[s - i]) % 998244353;
    //for (int i = 0; i <= s; i++) cout << d[i] << ' ' << f[i] << '\n';
    //cout << l << ' ' << r << ' ' << z << '\n';
    return (z + sol(l, m) + sol(m + 1, r)) % 998244353;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << sol(1, n);
}
