from itertools import combinations
N=input()
K=int(input())
L = len(N)
dp = [[[0]*(L+1) for _ in range(K+2)] for _ in range(2)]
#dp[smaller][j][i]:=上からiケタ目までを確定したときの場合の数
#smaller = 0: 一致
#j: 0意外の数

dp[0][0][0] = 1
for i in range(1, L+1):
    num = int(N[i-1])
    for k in range(K+1):
        dp[1][k][i] += dp[1][k][i-1]
        dp[1][k+1][i] += dp[1][k][i-1]*9
        
        if num > 0:
            dp[1][k][i] += dp[0][k][i-1]
            dp[1][k+1][i] += dp[0][k][i-1] * (num-1)
        
        if num > 0:
            dp[0][k+1][i] = dp[0][k][i-1]
        else:
            dp[0][k][i] = dp[0][k][i-1]

print(dp[0][K][L] + dp[1][K][L])