#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char s[10001];
int M = 1e9+7, d, dp[10001][101][2], n;

int solve(int i = 0, int m = 0, int f = 0) {
    if (i == n) {
        return m==0;
    }
    int& ret = dp[i][m][f];
    if (~ret) {
        return ret;
    }
    ret = 0;
    for (int j = 0; j <= 9; ++j) {
        if (j> s[i]-'0' && !f) {
            break;
        }
        ret += solve(i+1, (m+j)%d, f || (j < s[i]-'0'));
        if (ret >= M) {
            ret -= M;
        }
    }
    return ret;
}
int main() {
    scanf("%s %d", s, &d);
    n = strlen(s);
    memset(dp, -1, sizeof dp);
    int ans = solve()-1;
    if (ans == -1) {
        ans = M-1;
    }
    printf("%d\n", ans);
    return 0;
}
