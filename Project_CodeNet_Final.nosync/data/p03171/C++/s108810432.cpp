#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 3003
using namespace std;
typedef long long ll;

int n, a[N];
ll f[N][N], sum[N];

ll dp(int l, int r) {
    if (f[l][r] != -1) return f[l][r];
    ll &res = f[l][r];
    if (l == r) return res = a[l];
    else return res = sum[r] - sum[l - 1] - min(dp(l + 1, r), dp(l, r - 1));
}

int main() {
#ifdef whyqx
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif
    memset(f, -1, sizeof f);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    cout << dp(1, n) * 2 - sum[n];
    return 0;
}
