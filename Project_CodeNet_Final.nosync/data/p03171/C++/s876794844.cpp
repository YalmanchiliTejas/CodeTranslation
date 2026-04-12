#include <cstdio>
#include <algorithm>

const int MAXN = 3005;

int a[MAXN];
long long f[MAXN][MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) f[i][i] = a[i];
    for (int len = 2; len <= n; len++) for (int l = 1; l + len - 1 <= n; l++) {
        int r = l + len - 1;
        f[l][r] = std::max(a[l] - f[l + 1][r], a[r] - f[l][r - 1]);
    }

    printf("%lld\n", f[1][n]);
    
    return 0;
}