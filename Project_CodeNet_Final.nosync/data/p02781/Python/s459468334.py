n = input()
k = int(input())
l = len(n)

dp0 = [[0] * (k + 1) for _ in range(l + 1)]
dp1 = [[0] * (k + 1) for _ in range(l + 1)]

for i in range(1, l + 1):
    dp0[i][0] = 1

dp1[0][0] = 1

for i in range(1, l + 1):
    for j in range(1, k + 1):
        m = int(n[i - 1])
        if m != 0:
            dp0[i][j] = dp0[i-1][j-1] * 9 + dp0[i-1][j] + dp1[i-1][j-1] * (m-1) + dp1[i-1][j]
            dp1[i][j] = dp1[i-1][j-1]
        else:
            dp0[i][j] = dp0[i-1][j-1] * 9 + dp0[i-1][j]
            dp1[i][j] = dp1[i-1][j]

print(dp0[l][k] + dp1[l][k])