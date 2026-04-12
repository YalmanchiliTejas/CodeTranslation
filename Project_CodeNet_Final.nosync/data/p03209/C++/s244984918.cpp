#include<cstdio>

int n;
long x, ans;
long po[51];

void dfs(int n, long x) {
    if (x == 2 * po[n] - 1) ans += po[n];
    else if (x >= po[n]) {
        ans += po[n - 1] + 1;
        dfs(n - 1, x - po[n]);
    }
    else if (x > 0) {
        dfs(n - 1, x - 1);
    }
}

int main() {
    scanf("%d %ld", &n, &x);
    po[0] = 1;
    for (int i = 1; i <= n; i++) po[i] = 2 * po[i - 1] + 1;
    dfs(n, x);
    printf("%ld\n", ans);
    return 0;
}   
