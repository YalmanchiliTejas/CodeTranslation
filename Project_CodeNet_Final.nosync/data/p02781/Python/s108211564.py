N = [int(x) for x in input()]
K = int(input())

D = len(N)
dp = [[[0] * 4 for _ in range(2)] for _ in range(D + 1)]
dp[0][0][0] = 1

for i in range(D):
    for j in range(2):
        for d in range(10 if j else N[i] + 1):
            for k in range(4):
                if d:
                    if k + 1 <= 3:
                        dp[i + 1][j | (d < N[i])][k + 1] += dp[i][j][k]
                    else:
                        continue
                else:
                    dp[i + 1][j | (d < N[i])][k] += dp[i][j][k]

print(dp[D][0][K] + dp[D][1][K])