N = int(input())
a = list(map(int,input().split()))

dp = [[0]*(N+1) for _ in range(N+1)]

for i in range(N-1, -1, -1):
    for j in range(i, N):
        dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1])

print(dp[0][N-1])