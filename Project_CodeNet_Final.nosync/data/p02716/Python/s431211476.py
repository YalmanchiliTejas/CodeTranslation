N = int(input())
A = list(map(int, input().split()))

INF = 10 ** 18

if N % 2:
    dp = [[-INF for j in range(N)] for i in range(3)]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    dp[2][2] = A[2]
    for j in range(N):
        for i in range(3):
            if dp[i][j] == -INF:
                continue
            for k in range(3):
                if i + k < 3 and j + k + 2 < N:
                    dp[i + k][j + k + 2] = max(dp[i + k][j + k + 2], dp[i][j] + A[j + k + 2])
    print(max(max(dp[0][-3:-1]), max(dp[1][-2:]), max(dp[2][-1:])))
    
else:
    dp = [[-INF for j in range(N)] for i in range(2)]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    for j in range(N):
        for i in range(2):
            if dp[i][j] == -INF:
                continue
            for k in range(2):
                if i + k < 2 and j + k + 2 < N:
                    dp[i + k][j + k + 2] = max(dp[i + k][j + k + 2], dp[i][j] + A[j + k + 2])
    print(max(max(dp[0][-2:]), max(dp[1][-1:])))