n = input()
k = int(input())
l = len(n)
dp0 = [[0 for _ in range(k+1)] for i in range(l+1)]
dp1 = [[0 for _ in range(k+1)] for i in range(l+1)]
dp0[0][0] = 1
for i in range(l):
  t = int(n[i])
  for j in range(k+1):
    if j == 0:
      dp0[i+1][j] = 0 if t != 0 else dp0[i][j]
      dp1[i+1][j] = dp1[i][j]
      if t != 0:
        dp1[i+1][j] += dp0[i][j]
    else:
      if t != 0:
        dp0[i+1][j] =  dp0[i][j-1]
      else:
        dp0[i+1][j] = dp0[i][j]
      dp1[i+1][j] = dp1[i][j] + dp1[i][j-1]*9
      if t != 0:
        dp1[i+1][j] += dp0[i][j]
      dp1[i+1][j] += dp0[i][j-1]*max(t-1, 0)
print(dp0[l][k] + dp1[l][k])