#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 10001;
const int D = 101;
int dp[N][D][2];
int d, n;
char s[N];

int solve(int idx, int mod, bool lastDigit) {
    if (idx == n) {
        return mod == 0;
    }
    int& ans = dp[idx][mod][lastDigit];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    if (lastDigit) {
        for (int i = 0; i <= s[idx] - '0'; i++) {
            ans += solve(idx + 1, (mod + (i) % d) % d, i == s[idx] - '0');
            ans %= MOD;
        }
    } else {
        for (int i = 0; i < 10; i++) {
            ans += solve(idx + 1, (mod + (i) % d) % d, false);
            ans %= MOD;
        }
    }
    return ans;
}

int main() {
    scanf("%s%d", s, &d);
    n = strlen(s);
    memset(dp, -1, sizeof dp);
    printf("%d\n", (solve(0, 0, true) - 1 + MOD) % MOD);
    return 0;
}
