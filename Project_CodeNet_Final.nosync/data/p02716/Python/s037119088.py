N = int(input())
A = list(map(int, input().split()))
if N % 2 == 0:
    NINF = -(10 ** 16)
    dp = [[NINF for j in range(2)] for i in range(N)]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    for i in range(N):
        if i - 2 >= 0:
            if dp[i - 2][0] != NINF:
                dp[i][0] = dp[i - 2][0] + A[i]
            if dp[i - 2][1] != NINF:
                dp[i][1] = dp[i - 2][1] + A[i]
        if i - 3 >= 0:
            dp[i][1] = max(dp[i][1], dp[i - 3][0] + A[i])

    res = max(dp[N - 1][1], dp[N - 2][0])
else:
    NINF = -(10 ** 16)
    dp = [[NINF for j in range(3)] for i in range(N)]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    dp[2][2] = A[2]
    for i in range(N):
        if i - 2 >= 0:
            if dp[i - 2][0] != NINF:
                dp[i][0] = dp[i - 2][0] + A[i]
            if dp[i - 2][1] != NINF:
                dp[i][1] = dp[i - 2][1] + A[i]
            if dp[i - 2][2] != NINF:
                dp[i][2] = dp[i - 2][2] + A[i]
        if i - 3 >= 0:
            dp[i][1] = max(dp[i][1], dp[i - 3][0] + A[i])
            dp[i][2] = max(dp[i][2], dp[i - 3][1] + A[i])
        if i - 4 >= 0:
            dp[i][2] = max(dp[i][2], dp[i - 4][0] + A[i])

    res = max(dp[N - 1][2], dp[N - 2][1], dp[N - 3][0])

print(res)
