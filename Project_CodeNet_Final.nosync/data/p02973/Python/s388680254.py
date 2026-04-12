from bisect import bisect

N = int(input())
A = [int(input()) for _ in range(N)]

INF = 10**10
dp = [-INF]
for a in A:
    if a <= -dp[-1]:
        dp.append(-a)
    else:
        i = bisect(dp, -a)
        dp[i] = -a
ans = len(dp) - 1
print(ans)
