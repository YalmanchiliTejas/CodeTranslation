#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
void read (int &x) {
    char ch = getchar(); x = 0;
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
} const int N = 1e5 + 5;
int n, x, m, res, w[N], a[N], tot, s[N];
signed main() {
    read (n), read (x), read (m);
    int now = x % m; res += now;
    a[++tot] = now, w[now] = 1;
    for (int i = 2; i <= n; ++i) {
        now = now * now % m;
        if (w[now]) {
            n -= (i - 1);
            for (int j = w[now]; j <= tot; ++j)
                s[j] = s[j - 1] + a[j];
            int len = tot - w[now] + 1;
            res += s[tot] * (n / len);
            n %= len;
            res += s[w[now] + n - 1];
        } else  res += now, a[++tot] = now, w[now] = tot;
    } return printf ("%lld\n", res), 0;
}
