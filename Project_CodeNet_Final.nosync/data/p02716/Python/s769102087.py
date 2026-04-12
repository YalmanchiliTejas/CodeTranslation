N = int(input())
A = list(map(int, input().split()))

if N % 2 == 0:
    dp = [[(-1)*10**15]*2 for _ in range(N)]
    dp[0][0] = A[0]
    dp[0][1] = 0
    dp[1][0] = A[0] + A[1]
    dp[1][1] = max(A[0], A[1])
    for i in range(N-2):
        dp[i+2][0] = max(dp[i+2][0], dp[i][0] + A[i+2])
        dp[i+2][1] = max(dp[i+2][1], dp[i][1] + A[i+2])
        dp[i+1][1] = max(dp[i+1][1], dp[i][0])
    dp[N-1][1] = max(dp[N-1][1], dp[N-2][0])
    print(dp[N-1][1])
else:
    dp = [[(-1)*10**15]*3 for _ in range(N)]
    dp[0][0] = A[0]
    dp[0][1] = 0
    dp[0][2] = 0
    dp[1][0] = A[0] + A[1]
    dp[1][1] = max(A[0], A[1])
    dp[1][2] = 0
    for i in range(N-2):
        dp[i+2][0] = max(dp[i+2][0], dp[i][0] + A[i+2])
        dp[i+2][1] = max(dp[i+2][1], dp[i][1] + A[i+2])
        dp[i+1][1] = max(dp[i+1][1], dp[i][0])
        dp[i+1][2] = max(dp[i+1][2], dp[i][1])
        dp[i+2][2] = max(dp[i+2][2], dp[i][2] + A[i+2], dp[i][0])
    dp[N-1][1] = max(dp[N-1][1], dp[N-2][0])
    dp[N-1][2] = max(dp[N-1][2], dp[N-2][1])
    print(dp[N-1][2])
