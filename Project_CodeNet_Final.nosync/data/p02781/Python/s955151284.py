N = int(input())
K = int(input())
n = str(N)
l = len(n)
dp0 = [[0 for _ in range(K+1)]  for _ in range(l+1)]
dp1 = [[0 for _ in range(K+1)]  for _ in range(l+1)]
dp0[0][0] = 1

for i in range(l):
    x = int(n[i])
    for j in range(K):
        dp1[i+1][j+1] += dp1[i][j]*9
        dp1[i+1][j] += dp1[i][j]
        if x > 0:
            dp1[i+1][j] += dp0[i][j]
            dp1[i+1][j+1] += dp0[i][j]*(x-1)
            dp0[i+1][j+1] += dp0[i][j]
        else:
            dp0[i+1][j] += dp0[i][j]
    dp1[i+1][K] += dp1[i][K]
    if x > 0:
        dp1[i+1][K] += dp0[i][K]
    else:
        dp0[i+1][K] += dp0[i][K]
print(dp0[-1][-1]+dp1[-1][-1])
