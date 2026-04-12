#!/usr/bin/env python3
import sys
input = sys.stdin.readline
MOD = 998244353

n, s = map(int, input().split())
a = [int(item) for item in input().split()]

dp = [[0] * (s+1) for _ in range(n)]
dp[0][0] = 1
if a[0] <= s:
    dp[0][a[0]] = 1
ans = 0
for i, item in enumerate(a[1:]):
    for j in range(s+1):
        # Not use item
        dp[i+1][j] += dp[i][j]
        dp[i+1][j] %= MOD
        # Do use item
        if j + item <= s:
            dp[i+1][j + item] += dp[i][j]
            dp[i+1][j + item] %= MOD
    # Start from i
    if item <= s:
        dp[i+1][item] += 1
    dp[i+1][0] += 1
    ans += dp[i+1][s]
    ans %= MOD

print(ans)