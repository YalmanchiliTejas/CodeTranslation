#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3000 + 10;

int n;
ll a[MAXN], f[MAXN][MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for (int l = n; l >= 1; --l) {
        for (int r = l; r <= n; ++r) {
            f[l][r] = max(a[l] - f[l + 1][r], a[r] - f[l][r - 1]);
        }
    }
    printf("%lld", f[1][n]);
    return 0;
}