N = int(input())
K = int(input())

Ns = list(map(int,list(str(N))))
L = len(Ns)
    
dp = [[[0]*L for i in range(5)] for j in range(2)]
dp[0][1][0] = 1 # strict
dp[1][1][0] = Ns[0] - 1 # loose
dp[1][0][0] = 1
for i in range(L-1):
    n = Ns[i+1]
    for j in range(4): # 0,1,2,3
        if n == 0:
            dp[0][j][i+1] += dp[0][j][i] # 0
            dp[1][j][i+1] += dp[1][j][i] # 0
            dp[1][j+1][i+1] += 9*dp[1][j][i] # 1 to 9
        else:
            dp[0][j+1][i+1] += dp[0][j][i] # n
            dp[1][j][i+1] += dp[0][j][i] # 0
            dp[1][j+1][i+1] += (n-1) * dp[0][j][i] # 1 to n-1
            dp[1][j][i+1] += dp[1][j][i] # 0
            dp[1][j+1][i+1] += 9*dp[1][j][i] # 1 to 9
print(dp[0][K][L-1] + dp[1][K][L-1])

