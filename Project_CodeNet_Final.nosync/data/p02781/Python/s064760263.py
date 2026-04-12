n = input()
k = int(input())
dp = [[0]*(k+1) for _ in range(2)]
dp[0][0] = 1
for i in range(len(n)):
    newdp = [[0]*(k+1) for _ in range(2)]
    for j in range(k+1):
        if n[i]=='0':
            newdp[0][j] = dp[0][j]
            newdp[1][j] = dp[1][j]
            if j>0:
                newdp[1][j] += dp[1][j-1]*9
        else:
            newdp[1][j] = dp[0][j] + dp[1][j]
            if j>0:
                newdp[0][j] = dp[0][j-1]
                newdp[1][j] += dp[0][j-1]*(int(n[i])-1) + dp[1][j-1]*9
    dp = newdp
print(dp[0][k]+dp[1][k])