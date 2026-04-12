N = input()
K = int(input())

dp = [[[0] * 5 for _ in range(2)] for _ in range(len(N) + 1)]
dp[0][0][0] = 1

for i in range(len(N)):
    D = int(N[i])
    for j in range(2):
        for k in range(5):
            dMax = 9 if j else D
            for d in range(dMax + 1):
                dp[i + 1][j | (d < D)][min(4, k + (d != 0))] += dp[i][j][k]

ans1 = dp[len(N)][0][K]
ans2 = dp[len(N)][1][K]

print(ans1 + ans2)
