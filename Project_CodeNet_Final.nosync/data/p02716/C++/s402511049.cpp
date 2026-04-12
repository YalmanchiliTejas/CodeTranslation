#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

LL a[200005];
LL suffix[200005];
int n;
int t;

LL mem[200005][3];
LL vis[200005][3];

LL dp(int x, int miss) {
    if (x >= n) {
        return 0;
    } else if (n % 2 == 1 && miss == 2) {
        return suffix[x];
    } else if (n % 2 == 0 && miss == 1) {
        return suffix[x];
    } else if (vis[x][miss]) {
        return mem[x][miss];
    }
    LL ret = max(dp(x + 1, miss + 1), a[x] + dp(x + 2, miss));
    vis[x][miss] = true;
    mem[x][miss] = ret;
    return ret;
}

int main() {
    scanf("%d", &n);
    LL t = n / 2;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    suffix[n + 1] = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
        suffix[i] = suffix[i + 2] + a[i];
    }
    printf("%lld\n", dp(0, 0));
}
