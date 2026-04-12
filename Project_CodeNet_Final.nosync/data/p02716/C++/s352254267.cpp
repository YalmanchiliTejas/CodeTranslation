#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long INF = -1e18;


int a[200010];
long long f[200010], g[200010];
long long s[200010][2];
int n;

long long dfs1(int x) {
    if(x > n) return 0;
    if(g[x] > INF) return g[x];
    long long r1, r2;
    r1 = a[x] + dfs1(x + 2);
    r2 = s[x + 1][(x + 1) % 2];
    g[x] = max(r1, r2);
    return g[x];
}

long long dfs(int x) {
    if(x > n) return 0;
    if(f[x] > INF) return f[x];
    long long r1, r2, r3;
    r1 = a[x] + dfs(x + 2);
    r2 = a[x + 1] + dfs1(x + 3);
    r3 = s[x + 2][x % 2];
    f[x] = max(f[x], r1);
    f[x] = max(f[x], r2);
    f[x] = max(f[x], r3);
    return f[x];
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[i] = g[i] = -1e18;
    }
    for(int i = n; i >= 1; i--) {
        s[i][0] = s[i + 1][0];
        s[i][1] = s[i + 1][1];
        s[i][i % 2] = s[i + 1][i % 2] + a[i];
    }
    if(n % 2 == 0) {
        printf("%lld\n", dfs1(1));
    } else {
        printf("%lld\n", dfs(1));
    }

    return 0;
}
