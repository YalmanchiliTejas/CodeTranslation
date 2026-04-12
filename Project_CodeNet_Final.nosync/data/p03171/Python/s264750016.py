n = int(input())
A = list(map(int,input().split()))
dp = [[0]*(n+1) for _ in range(n+1)]
for k in range(1,n+1):
    for i in range(n+1-k):
        if (n-k)%2==0:
            dp[i][i+k] = max(dp[i+1][i+k] + A[i], dp[i][i+k-1] + A[i+k-1])
        else:
            dp[i][i+k] = min(dp[i+1][i+k] - A[i], dp[i][i+k-1] - A[i+k-1])
print(dp[0][n])