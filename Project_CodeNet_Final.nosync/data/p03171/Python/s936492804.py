N = int(input())
a = list(map(int, input().split()))
dp = [[0] * (N + 1) for i in range(N + 1)]
for k in range(1, N + 1):
    for l in range(N - k + 1):
        r = l + k
        if (N - k) % 2 == 0:
            dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1])
        else:
            dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1])

print(dp[0][N])

