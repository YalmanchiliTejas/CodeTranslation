import sys
input = sys.stdin.readline

K = input()[:-1]
D = int(input())
L = len(K)
dp = [[[0]*D for _ in range(2)] for _ in range(L+1)]
dp[0][0][0] = 1
MOD = 10**9+7

for i in range(L):
    Ki = int(K[i])
    
    for j in range(2):
        for k in range(D):
            for d in range(10 if j else Ki+1):
                dp[i+1][j|(d<Ki)][(k+d)%D] += dp[i][j][k]
                dp[i+1][j|(d<Ki)][(k+d)%D] %= MOD

print((dp[L][0][0]+dp[L][1][0]-1)%MOD)