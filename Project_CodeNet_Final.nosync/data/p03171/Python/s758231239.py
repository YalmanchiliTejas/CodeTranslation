N = int(input())
arr = list(map(int, input().split()))
dp = [[0]*(N+1) for _ in range(N+1)]
for i in range(1, N+1):
    for k in range(N-i+1):
        j = k+i
        if (N-i)%2 == 0:
            dp[k][j] = max(dp[k+1][j]+arr[k], dp[k][j-1]+arr[j-1])
        else:
            dp[k][j] = min(dp[k+1][j]-arr[k], dp[k][j-1]-arr[j-1])
print(dp[0][N])