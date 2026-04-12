N = int(input())
A = list(map(int, input().split()))
dp = [[0] * 4 for _ in range(200005)]
k = 1 + N % 2
for i in range(N + 1):
    for j in range(k + 1):
        dp[i][j] = - float('inf')
dp[0][0] = 0
for i in range(N):
    for j in range(k + 1):
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j])
        now = dp[i][j]
        if (i + j) % 2 == 0:
            now += A[i]
        dp[i + 1][j] = max(dp[i + 1][j], now)
ans = dp[N][k]
print(ans)