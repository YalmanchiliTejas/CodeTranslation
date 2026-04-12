from math import factorial
N = int(input())
K = int(input())
strN = str(N)
lenN = len(strN)
#dp[i][j][k] をi:今何桁目を調べているか、j:未満フラグ、k:何個0以外を出したか、としてdpしたい
dp = [[[0]*(K+1) for i in range(2)] for j in range(lenN+1)]
dp[0][0][0] = 1
for i in range(lenN):
    for j in range(2):
        for k in range(K+1):
            if j == 0:
                if k != K:
                    if strN[i] == "0":
                        dp[i+1][j][k] += dp[i][j][k]
                    else:
                        dp[i+1][j][k+1] +=  dp[i][j][k]
                        dp[i+1][1][k+1] +=  (int(strN[i])-1) * dp[i][j][k]
                        dp[i+1][1][k] += dp[i][j][k]
                else:
                    dp[i+1][j][k] += dp[i][j][k]
            if j == 1:
                if k != K:
                    dp[i+1][j][k+1] += 9*dp[i][j][k]
                    dp[i+1][j][k] += dp[i][j][k]
                else:
                    dp[i+1][j][k] += dp[i][j][k]
print(dp[lenN][0][K] + dp[lenN][1][K])