import sys
readline = sys.stdin.readline

N = int(readline())
A = list(map(int, readline().split()))

if N % 2 == 0:
    dp = [[0, 0] for i in range(N)]
    dp[1] = [A[0], A[1]]
    for i in range(3, N, 2):
        dp[i][0] = dp[i - 2][0] + A[i - 1]
        dp[i][1] = max(dp[i - 2][0] + A[i], dp[i - 2][1] + A[i])
    print(max(dp[N - 1]))

else:
    dp = [[0, 0, 0] for i in range(N)]
    dp[0] = [A[0], 0, 0]

    for i in range(2, N, 2):
        dp[i][0] = dp[i - 2][0] + A[i]
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1] + A[i - 1])
        dp[i][2] = max(dp[i - 2][1] + A[i], dp[i - 2][2] + A[i])

    print(max(dp[N - 1]))