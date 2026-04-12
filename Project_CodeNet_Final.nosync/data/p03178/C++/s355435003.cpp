#include <stdio.h>
#include <string.h>

const int MAX_LEN = 10005;
const int MAX_D = 105;
const int MOD = (int)1e9 + 7;

int dp[MAX_LEN][MAX_D][2];

char k[MAX_LEN];
int len;
int d;

int solve(int pos, int mod, int flag) {
    if (pos >= len) return mod == 0;
    if (dp[pos][mod][flag] != -1) return dp[pos][mod][flag];

    int& ans = dp[pos][mod][flag];
    ans = 0;
    for (int i = 0; i <= 9; i++) {
        if (flag == 0) {
            int digit = k[pos] - '0';
            if (i > digit) break;
            ans += solve(pos + 1, (mod + i) % d, i < digit);
        } else {
            ans += solve(pos + 1, (mod + i) % d, flag);
        }
        ans %= MOD;
    }
    ans %= MOD;
    return ans;
}

int main(void) {
    scanf(" %s", k);
    scanf(" %d", &d);

    len = strlen(k);
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0, 0);
    printf("%d\n", (ans - 1 + MOD) % MOD);

    return 0;
}
