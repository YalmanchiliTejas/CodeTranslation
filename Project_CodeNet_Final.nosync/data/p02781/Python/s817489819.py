import numpy as np
N = input()
K = int(input())
L = len(N)
dp0 = [[0]*(K+1) for i in range(L+1)]
dp1 = [[0]*(K+1) for i in range(L+1)]
dp0[0][0] = 1
for i in range(1,L+1):#i桁目
  c = int(N[i-1])
  for j in range(K+1):#k個0を使っているとする
    if j==0:
      if c>0:
        dp1[i][j] = dp1[i-1][j]+dp0[i-1][j]
        dp0[i][j] = 0
      else:
        dp1[i][j] = dp1[i-1][j]
        dp0[i][j] = dp0[i-1][j]
    else:
      if c>0:
        dp1[i][j] = dp0[i-1][j-1]*(c-1)+dp1[i-1][j-1]*9+dp1[i-1][j]+dp0[i-1][j]
        dp0[i][j] = dp0[i-1][j-1]
      else:
        dp1[i][j] = dp1[i-1][j-1]*9+dp1[i-1][j]
        dp0[i][j] = dp0[i-1][j]
print(dp0[-1][-1]+dp1[-1][-1])
