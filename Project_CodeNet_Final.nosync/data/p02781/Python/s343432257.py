n = input()
a = list(n)
k = int(input())
n = len(a)
for i in range(n):
    a[i] = int(a[i])
dp = [[[0 for i in range(2)] for i in range(k+2)]for i  in range(n)]
dp[0][0][0] = 1
dp[0][1][0] = a[0]-1
dp[0][1][1] = 1
for i in range(n-1):
    for j in range(k+1):
        if a[i+1] == 0:
            dp[i+1][j][1] += dp[i][j][1]
            dp[i+1][j][0] += dp[i][j][0]
            dp[i+1][j+1][0] += dp[i][j][0]*9
        else:
            dp[i+1][j][0] += dp[i][j][0]+dp[i][j][1]
            dp[i+1][j+1][0] += dp[i][j][1]*(a[i+1]-1)+dp[i][j][0]*9
            dp[i+1][j+1][1] += dp[i][j][1]
print(dp[n-1][k][0]+dp[n-1][k][1])