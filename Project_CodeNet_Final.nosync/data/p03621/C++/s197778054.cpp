#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const int MAXN = 10001;
const int MOD = 998244353;

int pw(int a, int b = MOD - 2) {
    return 0;
}

array<int, MAXN> f, fc, f2, f2c;

string a, b;

int mul(int a, int b) {
    return (ll(a) * b) % MOD;
}

template <typename ... TArgs>
int mul(int x, TArgs&& ... args) {
    return mul(x, mul(std::forward<TArgs>(args)...));
}

int main() {
#ifdef PAUNSVOKNO
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20);
    cin >> a >> b;
    int n = a.length();

    int k = 0, c = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == '1') {
            k++;
            c += (b[i] - '0');
        }

    f.fill(0);
    f2.fill(0);

    f[0] = 1;

    for (int i = 1; i <= k; i++) {
        fc = f;
        f2c = f2;
        f.fill(0), f2.fill(0);
        for (int j = 0; j <= i; j++) {
            int d = i - j;
            ll ans = 0;

            if (j > 0) {
                f2[j] += mul(fc[j - 1], i);
                if (j > 1) f2[j] += mul(i, j - 1, f2c[j - 1]);
                f2[j] %= MOD;
            }

            if (j) ans += mul(j, fc[j - 1]);
            if (j > 1) {
                ans += mul(j, j - 1, f2c[j - 1]);
            }
            if (d) ans += mul(d, d, fc[j]);
            if (j > 0) ans += mul(j, d, fc[j - 1]);

            f[j] = ans % MOD;
        }

    }

    cout << f[c] << "\n";
}