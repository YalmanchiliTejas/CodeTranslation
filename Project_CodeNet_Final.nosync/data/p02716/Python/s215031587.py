import sys

N = int(input())
A = list(map(int,input().split()))

INF = 10**20
dp = [[[-INF]*2 for _ in range(2)] for _ in range(N+1)]


if N&1:
    dp[0][1][0] = 0
    for i in range(N):
        if i&1:
            dp[i+1][0][0] = max(dp[i][0][0], dp[i][0][1])
            dp[i+1][1][0] = max(dp[i][1][0], dp[i][1][1])
            dp[i+1][1][1] = dp[i][0][0] + A[i]

        else:
            dp[i+1][0][0] = max(dp[i][1][0], dp[i][1][1])
            dp[i+1][0][1] = dp[i][0][0] + A[i]
            dp[i+1][1][1] = dp[i][1][0] + A[i]

    ans = max(dp[N][0][0], dp[N][0][1])            

else:
    dp[0][1][0] = 0
    for i in range(N):
        if i&1:
            dp[i+1][1][0] = dp[i][1][1]
            dp[i+1][1][1] = dp[i][0][0] + A[i]            

        else:
            dp[i+1][0][0] = max(dp[i][1][0], dp[i][1][1])
            dp[i+1][1][1] = dp[i][1][0] + A[i]
    ans = max(dp[N][1][0], dp[N][1][1])

print(ans)