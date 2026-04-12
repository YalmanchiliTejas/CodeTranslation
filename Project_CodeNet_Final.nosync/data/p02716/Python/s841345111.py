N = int(input())
A = list(map(int, input().split()))

dp = [{} for __ in range(N+1)]

dp[0][0] = 0
dp[1][0] = 0
dp[1][1] = A[0]

for i in range(2, N+1):
    for j in range((i-1)//2, (i+1)//2+1):
        app = (dp[i-2][j-1] if j-1 in dp[i-2] else -float('inf')) + A[i-1]
        napp = dp[i-1][j] if j in dp[i-1] else -float('inf')
        dp[i][j] = max(app, napp)

print(dp[N][N//2])
