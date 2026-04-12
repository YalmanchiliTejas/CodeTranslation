N = input()
K = int(input())
L = len(N)

dp0 = [[0] * (K + 1) for _ in range(L + 1)]
dp1 = [[0] * (K + 1) for _ in range(L + 1)]

dp0[0][0] = 1

n = []
for i in N:
    n.append(int(i))

for i in range(L):
    D = n[i]
    for j in range(K + 1):
        if D == 0:
            dp0[i + 1][j] += dp0[i][j]
            dp1[i + 1][j] += dp1[i][j]
            if j < K:
                dp1[i + 1][j + 1] = dp1[i][j] * 9
        else:
            dp1[i + 1][j] += (dp0[i][j] + dp1[i][j])
            if j < K:
                dp0[i + 1][j + 1] += dp0[i][j]
                dp1[i + 1][j + 1] += (D - 1) * dp0[i][j]
                dp1[i + 1][j + 1] += 9 * dp1[i][j]

print(dp0[L][K] + dp1[L][K])