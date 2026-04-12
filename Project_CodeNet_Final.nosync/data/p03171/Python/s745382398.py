import numpy as np

N = int(input())
A = tuple(map(int, input().split()))

dp = np.zeros((N + 1, N + 1), dtype=np.int64)
for m in range(1, N + 1):
    if (N - m) % 2:
        dp[m][:N - m + 1] = np.minimum(dp[m - 1][1:N - m + 2] - A[:N - m + 1],
                                       dp[m - 1][:N - m + 1] - A[m - 1:])
    else:
        dp[m][:N - m + 1] = np.maximum(dp[m - 1][1:N - m + 2] + A[:N - m + 1],
                                       dp[m - 1][:N - m + 1] + A[m - 1:])

print(dp[N][0])
