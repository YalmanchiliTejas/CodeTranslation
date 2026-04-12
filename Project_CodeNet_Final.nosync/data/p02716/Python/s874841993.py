INF = 10**18

N = int(input())
A = list(map(int, input().split()))

if N % 2 == 0:
    od = [0 for _ in range(N // 2 + 1)]
    ev = [0 for _ in range(N // 2 + 1)]

    for i in range(N):
        if i % 2 == 0:
            od[i // 2 + 1] = od[i // 2] + A[i]
        else:
            ev[~(i // 2 + 1)] = ev[~(i // 2)] + A[~i + 1]

    res = -INF

    for i in range(N // 2 + 1):
        res = max(res, od[i] + ev[i])

    print(res)

else:
    dp = [[[-INF for k in range(2)] for j in range(3)] for i in range(N + 1)]
    dp[0][0][0] = 0

    for i in range(N):
        dp[i + 1][0][0] = dp[i][0][1]
        dp[i + 1][1][0] = max(dp[i][0][0], dp[i][1][1])
        dp[i + 1][2][0] = max(dp[i][1][0], dp[i][2][1])
        dp[i + 1][0][1] = dp[i][0][0] + A[i]
        dp[i + 1][1][1] = dp[i][1][0] + A[i]
        dp[i + 1][2][1] = dp[i][2][0] + A[i]

    res = -INF

    for j in range(1, 3):
        for k in range(2):
            if k == 0 and j == 2:
                continue
            res = max(res, dp[N][j][k])

    print(res)