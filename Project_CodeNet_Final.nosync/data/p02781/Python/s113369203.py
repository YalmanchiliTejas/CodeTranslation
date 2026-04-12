n = int(input())
k = int(input())
s = str(n)
l = len(s)
dp0 = [[0]*(k+1) for _ in range(l+1)]
dp1 = [[0]*(k+1) for _ in range(l+1)]
dp1[0][0] = 1
for i in range(l):
  for j in range(k+1):
    dp1[i+1][j] += dp1[i][j]*(int(s[i]) == 0)
    dp0[i+1][j] += dp0[i][j]+dp1[i][j]*(int(s[i]) > 0)
    if j < k:
      dp1[i+1][j+1] += dp1[i][j]*(int(s[i]) > 0)
      dp0[i+1][j+1] += dp0[i][j]*9+dp1[i][j]*max(0,int(s[i])-1)
print(dp1[l][k]+dp0[l][k])