N = int(input())
*A, = map(int,input().split())

if N%2==0:
    INF = 2* 10**9
    dp = [[-INF]*N for _ in [0]*2]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    for i in range(2,N,2):
        a = A[i]
        dp[0][i] = dp[0][i-2] + a
    for i in range(3,N):
        a = A[i]
        dp[1][i] = max(dp[1][i-2],dp[0][i-3]) + a
    print(max(dp[1][-1],dp[0][-2]))
else:
    INF = 2* 10**9
    dp = [[-INF]*N for _ in [0]*3]
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    dp[2][2] = A[2]
    for i in range(2,N,2):
        a = A[i]
        dp[0][i] = dp[0][i-2] + a
    for i in range(3,N):
        a = A[i]
        dp[1][i] = max(dp[1][i-2],dp[0][i-3]) + a
    for i in range(4,N,2):
        a = A[i]
        dp[2][i] = max(dp[2][i-2],dp[1][i-3],dp[0][i-4]) + a
    print(max(dp[2][-1],dp[1][-2],dp[0][-3]))