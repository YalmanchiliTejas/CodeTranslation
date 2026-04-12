N = int(input())
A = tuple(map(int, input().split()))
dp = [[0] * (N + 1) for _ in range(N + 1)]

for length in range(1, N + 1):
    for l in range(N - length + 1):
        r = length + l
        if (N - length) % 2:
            dp[l][r] = min(dp[l + 1][r] - A[l], dp[l][r - 1] - A[r - 1])
        else:
            dp[l][r] = max(dp[l + 1][r] + A[l], dp[l][r - 1] + A[r - 1])
print(dp[0][N])
