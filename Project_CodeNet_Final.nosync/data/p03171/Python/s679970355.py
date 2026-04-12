from sys import stdin
input = stdin.readline

N = int(input())
a = list(map(int, input().split()))

dp = [[0] * (N + 1) for _ in range(N + 1)]

for i in range(N):
    dp[i][i + 1] = a[i] if N & 1 == 1 else -a[i]

for j in range(2, N + 1):
    for i in range(0, N + 1 - j):
        # j is the length of the interval + 1
        if (N - j) & 1 == 0:
            dp[i][i + j] = max(a[i] + dp[i + 1][i + j],
                               a[i + j - 1] + dp[i][i + j - 1])
        else:
            dp[i][i + j] = min(dp[i + 1][i + j] - a[i],
                               dp[i][i + j - 1] - a[i + j - 1])

print(dp[0][N])
