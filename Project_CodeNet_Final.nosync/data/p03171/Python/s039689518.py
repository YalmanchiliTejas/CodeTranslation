N = int(input())
A = list(map(int, input().split()))

INF = 10 ** 12

dp1 = [[-INF] * (N + 1) for _ in range(N + 1)] #X - Yの最大値
dp2 = [[+INF] * (N + 1) for _ in range(N + 1)] #X - Yの最小値

if N % 2 == 0: #偶数-->最後の一個はY
    for i in range(N):
        dp2[i][i + 1] = -A[i]
        # print (dp2[i][i + 1], end =' ')
    # print ()
    for k in range(2, N + 1):
        if k % 2 == 1:
            for i in range(N - k + 1):
                dp2[i][i + k] = min(dp1[i][i + k - 1] - A[i + k - 1], dp1[i + 1][i +k] - A[i])
                # print (dp2[i][i + k], end = ' ')
            # print ()
        else:
            for i in range(N - k + 1):
                dp1[i][i + k] = max(dp2[i][i + k - 1] + A[i + k - 1], dp2[i + 1][i + k] + A[i])
                # print (dp1[i][i + k], end = ' ')
            # print ()
    print (dp1[0][N])



else: #奇数-->最後の一個はX
    for i in range(N):
        dp1[i][i + 1] = A[i]
        # print (dp1[i][i + 1], end =' ')
    # print ()
    for k in range(2, N + 1):
        if k % 2 == 0:
            for i in range(N - k + 1):
                dp2[i][i + k] = min(dp1[i][i + k - 1] - A[i + k - 1], dp1[i + 1][i +k] - A[i])
                # print (dp2[i][i + k], end = ' ')
            # print ()
        else:
            for i in range(N - k + 1):
                dp1[i][i + k] = max(dp2[i][i + k - 1] + A[i + k - 1], dp2[i + 1][i + k] + A[i])
                # print (dp1[i][i + k], end = ' ')
            # print ()
    print (dp1[0][N])
