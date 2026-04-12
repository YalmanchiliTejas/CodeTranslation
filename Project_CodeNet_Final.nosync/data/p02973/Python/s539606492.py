
from bisect import bisect_right

N = int(input())
X = [int(input()) for _ in range(N)]

INF = 10 ** 9 + 7
dp = [INF] * (N + 1)
for i in range(N):
    dp[bisect_right(dp, -X[i])] = -X[i]

print(sum(v < INF for v in dp))
