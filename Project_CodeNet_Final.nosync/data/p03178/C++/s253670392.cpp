#include <bits/stdc++.h>
// S - Digit Sum

#define MOD 1000000007

using namespace std;

string K;
int dp[10005][105];
bool vis[10005];
int D,ans;

void solve2(int len) {
    if (vis[len])
        return;

    vis[len] = true;

    if (len == 0) {
        dp[len][0] = 1;
        return;
    }

    int i,j;

    solve2(len - 1);
    for (i = 0;i < D;i++) {
        for (j = 0;j < 10;j++) {
            dp[len][i] += dp[len - 1][(i - j + (D << 5)) % D];
            dp[len][i] %= MOD;
        }
    }
}

void solve1(int len,int rem) {
    if (len == 0) {
        if (rem == 0) {
            ans++;
            ans %= MOD;
        }
        return;
    }

    int i;

    for (i = 0;i + '0' < K[K.size() - len];i++) {
        solve2(len - 1);
        ans += dp[len - 1][((D << 5) - rem - i) % D];
        ans %= MOD;
    }

    solve1(len - 1,(rem + K[K.size() - len] - '0') % D);
}

int main() {
    cin >> K;
    cin >> D;

    ans = 0;
    solve1((int) (K.size()),0);

    printf("%d\n",(ans - 1 + MOD) % MOD);

    return 0;
}
