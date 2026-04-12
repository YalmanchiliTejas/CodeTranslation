from bisect import bisect
N, *A = map(int, open(0).read().split())

INF = 10 ** 9 + 7
dp = [INF] * (N + 1)
for i in range(N):
    dp[bisect(dp, -A[i])] = -A[i]

print(sum(dp[i] < INF for i in range(N)))