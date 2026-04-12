
N = int(input())
aa = list(map(int, input().split()))

if N % 2 == 0:
    dp = [[[0, 0] for j in range(2)] for i in range(N)]

    for i, a in enumerate(aa):
        dp[i][0][1] = dp[i - 1][0][0] + a
        dp[i][0][0] = dp[i - 1][0][1]

        dp[i][1][0] = max(dp[i - 1][1][1], dp[i - 1][0][0])
        dp[i][1][1] = dp[i - 1][1][0] + a

    print(max(max(dp[-1][0]), dp[-1][1][1]))
else:
    dp = [[[0, 0] for j in range(3)] for i in range(N)]

    for i, a in enumerate(aa):
        dp[i][0][1] = dp[i - 1][0][0] + a
        dp[i][0][0] = dp[i - 1][0][1]

        dp[i][1][0] = max(dp[i - 1][1][1], dp[i - 1][0][0])
        dp[i][1][1] = dp[i - 1][1][0] + a

        dp[i][2][0] = max(dp[i - 1][2][1], dp[i - 1][1][0])
        dp[i][2][1] = dp[i - 1][2][0] + a

    print(max(max(dp[-1][1]), dp[-1][2][1]))
