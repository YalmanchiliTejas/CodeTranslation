import sys
stdin = sys.stdin
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
a = na()

dp = [0]*n
b = a[0]

dp[1] = max(a[0],a[1])

for i in range(2,n):
    if i%2 == 0:
        b += a[i]
        dp[i] = max(dp[i-1],dp[i-2]+a[i])
    else:
        dp[i] = max(b,dp[i-2]+a[i])

print(dp[-1])