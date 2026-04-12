N = input()
digits = len(N)
K = int(input())
dp0 = [[0]*5 for i in range(digits + 1)] 
dp1 = [[0]*5 for i in range(digits + 1)]
dp0[0][0] = 1
for i, n in enumerate(N):
    n = int(n)
    for j in range(4):
        if n == 0:
            dp0[i+1][j] += dp0[i][j]
            dp1[i+1][j] += dp1[i][j]
            dp1[i+1][j+1] += 9 * dp1[i][j]
        else:
            dp0[i+1][j+1] += dp0[i][j]
            dp1[i+1][j] += dp0[i][j] + dp1[i][j]
            dp1[i+1][j+1] += (n - 1) * dp0[i][j] + 9 * dp1[i][j]
print(dp0[digits][K] + dp1[digits][K])     