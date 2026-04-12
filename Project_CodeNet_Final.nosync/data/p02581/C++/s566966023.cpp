#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 2005;

int a[N * 3], f[N][N], g[N], gt[N], now, ans;
void update(int x, int y, int t) {
    f[x][y] = max(f[x][y], t);
    now = max(now, t);
    gt[x] = max(gt[x], t);
    gt[y] = max(gt[y], t);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 3 * n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) f[i][j] = -INF;
    for (int i = 1; i <= n; i++) gt[i] = -INF;
    update(a[1], a[2], 0);
    for (int j = 1; j <= n; j++) g[j] = gt[j];
    ans = now;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int x = a[i * 3], y = a[i * 3 + 1], z = a[i * 3 + 2];
        if (x == y && x == z) {
            cnt++;
            continue;
        }
        if (x == y || x == z || y == z) {
            if (x == z) swap(y, z);
            if (y == z) swap(x, z);
            int t = f[z][z];
            int sb = f[x][z]; // 可能会被改掉
            for (int j = 1; j <= n; j++) {
                update(j, z, max(f[j][x], j == z ? sb : f[x][j]) + 1);
            }
            update(x, y, t + 1);
        } else {
            update(x, y, f[z][z] + 1);
            update(x, z, f[y][y] + 1);
            update(y, z, f[x][x] + 1);
        }
        for (int j = 1; j <= n; j++) {
            update(j, x, g[j]);
            update(j, y, g[j]);
            update(j, z, g[j]);
        }
        update(x, y, ans);
        update(x, z, ans);
        update(y, z, ans);
        for (int j = 1; j <= n; j++) g[j] = gt[j];
        ans = now;
    }
    ans = max(ans, f[a[n * 3]][a[n * 3]] + 1);
    printf("%d\n", ans + cnt);
    return 0;
}
