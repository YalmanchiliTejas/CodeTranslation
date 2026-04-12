S = input().strip()
N = len(S)
K = int(input())
dp = [[0]*(K+1) for _ in range(N+1)]
dp2 = [[0]*(K+1) for _ in range(N+1)]
dp[0][K] = 1
dp2[0][K] = 1
for i in range(N):
    for j in range(K+1):
        dp[i+1][j] = dp[i][j]
        if j != K: dp[i+1][j] += dp[i][j+1] * 9
    dd = int(S[N-i-1])
    for j in range(K+1):
        if dd == 0:
            dp2[i+1][j] = dp2[i][j]
        else:
            if j != K:
                dp2[i+1][j] = dp[i][j] + dp[i][j+1]*(dd-1) + dp2[i][j+1]
            else:
                dp2[i+1][j] = dp[i][j]
print(dp2[N][0])
