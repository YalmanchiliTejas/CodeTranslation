N = int(input())
*a, = map(int, input().split())

dp = [[0] *  N for _ in range(N)]
for i in range(N): dp[i][i] = a[i]

for j in range(1, N):
    for i in range(j-1, -1, -1):
        dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1])

print(dp[0][N-1])