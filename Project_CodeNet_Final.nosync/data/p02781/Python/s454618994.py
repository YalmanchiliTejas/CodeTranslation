
nn = list(map(int, list(input())))
L = len(nn)
K = int(input())

dp = [[[0] * (4) for _ in range(2)] for __ in range(L + 1)]


dp[0][0][0] = 1


for i, n in enumerate(nn):
    for x in range(0, 10):
        if x == 0:
            dp[i + 1][1][0] += dp[i][1][0]
            dp[i + 1][1][1] += dp[i][1][1]
            dp[i + 1][1][2] += dp[i][1][2]
            dp[i + 1][1][3] += dp[i][1][3]
        else:
            dp[i + 1][1][1] += dp[i][1][0]
            dp[i + 1][1][2] += dp[i][1][1]
            dp[i + 1][1][3] += dp[i][1][2]

    for x in range(0, n + 1):
        if x == 0:
            dp[i + 1][0 if x == n else 1][0] += dp[i][0][0]
            dp[i + 1][0 if x == n else 1][1] += dp[i][0][1]
            dp[i + 1][0 if x == n else 1][2] += dp[i][0][2]
            dp[i + 1][0 if x == n else 1][3] += dp[i][0][3]
        else:
            dp[i + 1][0 if x == n else 1][1] += dp[i][0][0]
            dp[i + 1][0 if x == n else 1][2] += dp[i][0][1]
            dp[i + 1][0 if x == n else 1][3] += dp[i][0][2]


print(dp[-1][0][K] + dp[-1][1][K])
