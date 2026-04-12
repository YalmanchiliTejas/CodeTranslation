#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 3001
ll f[N][N];
int a[N], n;
int main() {
    scanf("%d", &n);
    bool sign = n & 1 ? 1 : -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[i][i] = a[i] * sign;
    }
    for (int len = 1; len <= n; len++)
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            f[i][j] = max(a[i] - f[i + 1][j], a[j] - f[i][j - 1]);
        }
    printf("%lld\n", f[1][n]);
    return 0;
}