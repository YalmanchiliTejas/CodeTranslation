import bisect

N = int(input())
A = [10**10 - int(input()) for i in range(N)]
INF = 10**12

dp = [INF for i in range(N+1)]
#print(A,dp)

for a in A:
    i = bisect.bisect_right(dp,a)
    dp[i] = a
#print(dp)
res = bisect.bisect_left(dp,INF)
print(res)