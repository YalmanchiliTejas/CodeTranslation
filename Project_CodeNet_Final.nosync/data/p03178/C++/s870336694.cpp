#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 10005;

int digit[maxn], tot, d;
ll dp[maxn][105];

ll dfs(int len, int pre, int top) {
    if (!len) {
        if (pre == 0) return 1;
        return 0;
    }
    if (!top && dp[len][pre] != -1) return dp[len][pre];
    int up = (top ? digit[len] : 9);
    ll res = 0;
    for (int i = 0; i <= up; i++) {
        res += dfs(len - 1, (pre + i) % d, top && (i == up));
        res %= mod;
    }
    if (!top) dp[len][pre] = res;
    return res;
}

ll solve(int n) {
    memset(dp, -1, sizeof(dp));
    tot = n;
    return dfs(tot, 0, 1);
}
char str[maxn];
int main() {
   //freopen("in.in", "r", stdin);
//    freopen("o2.out", "w", stdout);
    scanf("%s%d", str + 1, &d);
    int n = strlen(str + 1);
    for (int i = n, j = 1; i >= 1; i--, j++) {
        digit[j] = str[i] - '0';
    }
    cout << (solve(n) - 1 + mod) % mod<< endl;
    return 0;
}