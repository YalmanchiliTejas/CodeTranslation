#coding:utf-8

N = input()
K = int(input())
dp = [[[0 for _ in range(K+2)] for _ in range(2)] for _ in range(len(N) + 1)]
# 桁数、０以外が出た回数、未満フラグ
dp[0][0][0] = 1

for i in range(len(N)):
    for smaller in range(2):
        for k in range(K+1):
            for x in range(10 if smaller == 1 else int(N[i]) + 1):
                dp[i + 1][smaller == 1 or x < int(N[i])][k + 1 if x != 0 else k] += dp[i][smaller][k]
print(dp[len(N)][0][K] + dp[len(N)][1][K])