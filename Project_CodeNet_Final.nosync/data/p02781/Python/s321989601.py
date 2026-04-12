import numpy as np

n = input()
k = int(input()) + 1
d = len(n)
dp0 = np.zeros((d, k), dtype=int)
dp1 = np.zeros((d, k), dtype=int)
dp0[0][0] = 1
dp0[0][1] = int(n[0]) - 1
dp1[0][1] = 1
for i in range(d - 1):
    for j in range(k):
        dp0[i + 1][j] = dp0[i][j]
        if j > 0:
            dp0[i + 1][j] += 9 * dp0[i][j - 1]
        m = int(n[i + 1])
        if m > 0:
            dp0[i + 1][j] += dp1[i][j]
            if j > 0:
                dp0[i + 1][j] += (m - 1) * dp1[i][j - 1]
                dp1[i + 1][j] = dp1[i][j - 1]
            else:
                dp1[i + 1][j] = 0
        else:
            dp1[i + 1][j] = dp1[i][j]
print(dp0[d - 1][k - 1] + dp1[d - 1][k - 1])