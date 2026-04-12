#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int n;
int a[200];
int mypow(int x, int n) {
    if (n == 0) return 1;
    int g = mypow(x, n / 2);
    g = 1ll * g * g % mod;
    if (n & 1) g = 1ll * g * x % mod;
    return g;
}
int f[200][200];
int good[5][5];
int b[200];
int ll[200], rr[200];
long long geomprog(int b, int k) {
    if (k <= 0) return 1;
    return mypow(b, k + 1) - 1;
}
int solve(int l, int r) {
    for (int j = l; j <= r; j++) b[j] = a[j];
    sort(b + l, b + r + 1);
    int c = 1, k = 0;
    for (int i = l; i <= r; i++) {
        if (b[i] != b[i - 1]) {
            k++;
            ll[k] = c;
            rr[k] = b[i] - 1;
            c = b[i];
        }
    }
    f[l][0] = 2;
    for (int j = 1; j <= k; j++)
        if (rr[j] < a[l]) f[l][j] = (geomprog(2, a[l] - ll[j]) - geomprog(2, a[l] - rr[j] - 1) + mod) % mod;
    for (int i = l; i < r; i++)
    for (int j = 0; j <= k; j++)
        if (f[i][j] != 0) {
            if (j == 0) {
                if (a[i] >= a[i + 1]) {
                    f[i + 1][0] += 2ll * f[i][j] % mod;
                    if (f[i + 1][0] >= mod) f[i + 1][0] -= mod;
                }
                else {
                    f[i + 1][0] += 2ll * f[i][j] % mod;
                    if (f[i + 1][0] >= mod) f[i + 1][0] -= mod;
                    for (int t = 1; t <= k; t++)
                        if (ll[t] >= a[i] && rr[t] < a[i + 1]) {
                            int c = (geomprog(2, a[i + 1] - ll[t]) - geomprog(2, a[i + 1] - rr[t] - 1) + mod) % mod;
                            f[i + 1][t] += 1ll * c * f[i][j] % mod;
                            if (f[i + 1][t] >= mod) f[i + 1][t] -= mod;
                        }
                }
            }
            else {
                if (rr[j] < a[i + 1]) {
                    int c = 1;
                    if (a[i + 1] > a[i]) c = mypow(2, a[i + 1] - a[i]);
                    f[i + 1][j] += 1ll * f[i][j] * c % mod;
                    if (f[i + 1][j] >= mod) f[i + 1][j] -= mod;
                }
                else {
                    f[i + 1][0] += 2ll * f[i][j] % mod;
                    if (f[i + 1][0] >= mod) f[i + 1][0] -= mod;
                }
            }
        }
    int s = 0;
    for (int j = 0; j <= k; j++) {
        s += f[r][j];
        if (s >= mod) s -= mod;
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    good[0][3] = good[3][0] = 1;
    good[1][2] = good[2][1] = 1;
    good[1][1] = good[2][2] = 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long c = 1; int prv = 0;
    a[n + 1] = 1;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] == 1) {
            if (i != n + 1) c = c * 2 % mod;
            if (prv + 1 <= i - 1) c = c * solve(prv + 1, i - 1) % mod;
            prv = i;
        }
    }
    cout << c << "\n";
    return 0;
}
