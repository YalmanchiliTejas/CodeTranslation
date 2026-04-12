N = input()
K = int(input())
L = len(N)
dp = [[[0]*4 for _ in range(2)] for _ in range(L+1)]
dp[0][0][0] = 1

for i in range(L):
    D = int(N[i])
    
    for j in range(2):
        for d in range(10 if j else D+1):
            for k in range(4):
                if d==0:
                    dp[i+1][j|(d<D)][k] += dp[i][j][k]
                else:
                    if k+1<=3:
                        dp[i+1][j|(d<D)][k+1] += dp[i][j][k]
    
print(dp[L][0][K]+dp[L][1][K])