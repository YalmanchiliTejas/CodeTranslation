n = int(input())
a = list(map(int,input().split()))

m = 2+n%2
dp = [[-10**18]*m for i in range(n+2)]
dp[0][0] = 0
for i in range(n):
    for j in range(m):
        if i%2 == j%2:
            x = a[i]
        else:
            x = 0
        if dp[i+1][j] < dp[i][j] + x:
            dp[i+1][j] = dp[i][j] + x
        if j+1 < m and dp[i+1][j+1] < dp[i][j]:
            dp[i+1][j+1] = dp[i][j]
print(max(dp[n][m-2], dp[n][m-1]))
