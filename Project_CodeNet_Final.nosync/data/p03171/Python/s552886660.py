n = int(input())
ns = list(map(int, input().split()))
dp = [[0] * n for i in range(n+1)]
for i in range(n+1, -1, -1):
    for j in range(i, n):
        if n % 2 == (i + j+1) % 2:
            dp[i][j] = max(dp[i + 1][j] + ns[i], dp[i][j - 1] + ns[j])
        else:
            dp[i][j] = min(dp[i + 1][j] - ns[i], dp[i][j - 1] - ns[j])
print(dp[0][-1])