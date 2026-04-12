N, K = map(int, open(0).read().split())

X = str(N + 1)
dp = [[[0] * (K + 1) for _ in range(2)] for _ in range(len(X) + 1)]
dp[0][0][0] = 1

for i in range(len(X)):
    D = int(X[i])
    for j in range(2):
        for k in range(K + 1):
            for d in range((9 if j == 1 else D) + 1):
                if k + int(d != 0) <= K:
                    dp[i + 1][j | (d < D)][k + int(d != 0)] += dp[i][j][k]

print(dp[-1][-1][-1])
