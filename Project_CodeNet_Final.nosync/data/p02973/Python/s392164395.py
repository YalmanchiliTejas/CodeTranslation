import bisect
n = int(input())
a = [int(input()) for _ in range(n)]

dp = [float('inf')]*n
for i in range(n):
    x = bisect.bisect_right(dp,-a[i])
    dp[x] = -a[i]
c = dp.count(float('inf'))
print(n-c)