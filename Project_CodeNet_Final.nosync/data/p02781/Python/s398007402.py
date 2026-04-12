# -*- coding: utf-8 -*-
# 整数の入力
#a = int(input())
# スペース区切りの整数の入力
#b, c = map(int, input().split())
# 文字列の入力
#s = input()
# 出力
#print("{} {}".format(a+b+c, s))

import numpy as np

nrow = input()
k = int(input())

l = len(nrow)

dp = np.zeros((l, 2, 4), int)
topmax = int(nrow[0])
dp[0, 0, 1] = 1  # =topmax
dp[0, 1, 0] = 1  # =0
dp[0, 1, 1] = topmax-1  # <topmax

for i in range(1, l):
  topmax = int(nrow[i])

  dp[i, 1, 0] = dp[i-1, 1, 0]  # =0
  for j in range(1,4):
    dp[i, 1, j] = dp[i-1, 1, j] + dp[i-1, 1, j-1] * 9  # =0,any

  if topmax == 0:
    for j in range(1, 4):
      dp[i, 0, j] = dp[i-1, 0, j]  #=0
  else:
    dp[i, 0, 2] = dp[i-1, 0, 1]  # =topmax,
    dp[i, 0, 3] = dp[i-1, 0, 2]  # =topmax,
    dp[i, 1, 1] += dp[i-1, 0, 1] # =0,<topmax
    dp[i, 1, 2] += dp[i-1, 0, 2]+dp[i-1, 0, 1] * (topmax-1)  # =0,<topmax
    dp[i, 1, 3] += dp[i-1, 0, 3]+dp[i-1, 0, 2] * (topmax-1)  # =0,<topmax

print(dp[l-1,0,k]+dp[l-1,1,k])
