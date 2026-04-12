import bisect

INF = 10000000000

n = int(input())
a = [0] * n

for i in range(n):
    a[i] = int(input())
    a[i] = - a[i]

dp = [INF] * n

for i in range(n):
    dp[bisect.bisect_right(dp,a[i])] = a[i]
    
print(bisect.bisect_left(dp,INF))