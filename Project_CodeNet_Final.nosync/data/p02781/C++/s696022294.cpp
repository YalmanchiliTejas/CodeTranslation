#include<cstdio>
#include<cstring>

char n[102];
int k, l, memo[101][3];

int dfs(int x, int cnt, bool f) {
    if (cnt == k) return 1;
    if (x == l) return 0;
    if (f && memo[x][cnt] != -1) return memo[x][cnt];
    int res = 0;
    if (f) {
        res += dfs(x + 1, cnt, true);
        for (int i = 1; i <= 9; i++) res += dfs(x + 1, cnt + 1, true);
    }
    else {
        res += dfs(x + 1, cnt, n[x] > '0');
        for (int i = 1; i <= n[x] - '0'; i++) res += dfs(x + 1, cnt + 1, i < n[x] - '0');
    }
    if (f) memo[x][cnt] = res;
    return res;
}

int main() {
    scanf("%s", n);
    scanf("%d", &k);
    l = strlen(n);
    memset(memo, -1, sizeof(memo));
    int ans = dfs(0, 0, false);
    printf("%d\n", ans);
    return 0;
}
