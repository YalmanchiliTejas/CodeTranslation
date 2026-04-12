from bisect import bisect_right

N, *A = map(int, open(0).read().split())

INF = 10 ** 10
dp = [INF] * N
for i in range(N):
    dp[bisect_right(dp, -A[i])] = -A[i]

print(max(i + 1 for i, v in enumerate(dp) if v < INF))
