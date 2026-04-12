import numpy as np

N = input()
K = int(input())
lt,eq = 0,1
dp = np.zeros((101,2,5),dtype=int)

dn = len(N)
dp[0][eq][0] = 1
for i in range(dn):
    di = ord(N[i]) - ord('0')
    for k in range(K+1):
        dp[i+1][lt][k] = dp[i][lt][k] * 1 + dp[i][eq][k] * (1 if di >= 1 else 0)
        if k:
            dp[i+1][lt][k] += dp[i][lt][k-1] * 9 + dp[i][eq][k-1] * max(0,di-1)
        if dp[i][eq][k]:
            dp[i+1][eq][k+(di>0)] = 1

print(int(dp[dn][lt][K] + dp[dn][eq][K]))