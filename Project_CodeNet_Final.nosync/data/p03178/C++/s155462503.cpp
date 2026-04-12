#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 10001;
const int D = 101;
int dp[N][D][2][2];
int d, n;
char s[N];

int solve(int idx, int mod, bool notZero, bool lastDigit) {
    if (idx == n) {
        return mod == 0 && notZero;
    }
    int& ans = dp[idx][mod][notZero][lastDigit];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    if (lastDigit) {
        for (int i = 0; i <= s[idx] - '0'; i++) {
            ans += solve(idx + 1, (mod + (i) % d) % d, notZero || i, i == s[idx] - '0');
            ans %= MOD;
        }
    } else {
        for (int i = 0; i < 10; i++) {
            ans += solve(idx + 1, (mod + (i) % d) % d, notZero || i, false);
            ans %= MOD;
        }
    }
    return ans;
}

int main() {
    scanf("%s%d", s, &d);
    n = strlen(s);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, 0, false, true));
    return 0;
}
