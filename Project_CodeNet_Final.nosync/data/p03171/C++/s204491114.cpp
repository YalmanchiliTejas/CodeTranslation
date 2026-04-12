#include <bits/stdc++.h>

using namespace std;
const int maxn = 3010;

int n;
int niz[maxn];
long long dp[maxn][maxn];

long long rek(int x, int y, bool turn) {
    if (x > y) return 0;
    long long &ret = dp[x][y];
    if (ret != -1) return ret;

    if (turn) ret = max(rek(x + 1, y, false) + niz[x], rek(x, y - 1, false) + niz[y]);
    else ret = min(rek(x + 1, y, true) - niz[x], rek(x, y - 1, true) - niz[y]);
    return ret;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", niz+i);

    printf("%lld", rek(0, n - 1, true));
    return 0;
}
