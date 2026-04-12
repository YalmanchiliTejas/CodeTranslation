import sys
from itertools import combinations
input = lambda: sys.stdin.readline().rstrip()
mod = 10**9 + 7
n = int(input())
a = list(map(int, input().split()))
dp = [0 for _ in range(n)]
dp[0] = a[0]

# 累積和の計算
for i in range(1, n):
    dp[i] = (a[i] + dp[i - 1]) % mod

ans = 0
for i in range(n):
    ans += a[i] * (dp[n - 1] - dp[i])
    ans %= mod

print(ans)
