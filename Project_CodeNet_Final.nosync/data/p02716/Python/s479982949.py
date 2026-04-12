N = int(input())
A = list(map(int, input().split()))

dp = [{} for _ in range(N + 2)]
dp[0][0] = 0
dp[-1][0] = 0

for i in range(1, N + 1):
    f = (i - 1) // 2
    t = (i + 1) // 2
    for j in range(f, t + 1):
        var1 = dp[i - 2][j - 1] + A[i - 1] if j - 1 in dp[i - 2] else -float('inf')
        var2 = dp[i - 1][j] if j in dp[i - 1] else -float('inf')
        dp[i][j] = max(var1, var2)

print(dp[N][N // 2])
