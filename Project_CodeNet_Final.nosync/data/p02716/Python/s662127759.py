n = int(input())
a = list(map(int, input().split()))
INF = 10 ** 20

dp = [{} for i in range(n + 1)]
dp[0][0] = 0

for i in range(n):
    for j in range(max((i + 1) // 2 - 4, 0), (i + 1) // 2 + 3):
        dp[i + 1][j + 1] = -INF
        if j in dp[max(0, i - 1)]:
            dp[i + 1][j + 1] = max(dp[max(0, i - 1)][j] + a[i], dp[i + 1][j + 1])
        if j in dp[max(0, i - 2)]:
            dp[i + 1][j + 1] = max(dp[max(0, i - 2)][j] + a[i], dp[i + 1][j + 1])
        if j in dp[max(0, i - 3)]:
            dp[i + 1][j + 1] = max(dp[max(0, i - 3)][j] + a[i], dp[i + 1][j + 1])
            
ans = -INF
for i in range(n + 1):
    if n // 2 in dp[i]:
        ans = max(ans, dp[i][n // 2])
print(ans)