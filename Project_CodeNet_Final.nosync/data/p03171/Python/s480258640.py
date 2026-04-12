N = int(input())
A = list(map(int,input().split()))

dp = [[0]*3100 for _ in range(3100)]
for length in range(1,N+1):
    for i in range(N-length+1):
        j = i + length

        # 先手番
        if (N-length)%2 == 0:
            dp[i][j] = max(dp[i+1][j] + A[i], dp[i][j-1] + A[j-1])

        # 後手番
        else:
            dp[i][j] = min(dp[i+1][j] - A[i], dp[i][j-1] - A[j-1])

print(dp[0][N])