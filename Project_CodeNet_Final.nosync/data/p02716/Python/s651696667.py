N = int(input())
MINF = float('-inf')
As = (map(int, input().split()))

dp = [[[0 for ___ in range(2)] for __ in range(2)] for _ in range(N+3)]

if N % 2 == 0:
    for i, a in enumerate(As):
        if i % 2 == 0:
            dp[i][0][0] = max(dp[i-2][1][1], dp[i-1][1][1])
            dp[i][0][1] = MINF
            dp[i][1][0] = MINF
            dp[i][1][1] = dp[i-2][1][1] + a
        else:
            dp[i][0][0] = MINF
            dp[i][0][1] = MINF
            dp[i][1][0] = dp[i-1][1][1]
            dp[i][1][1] = max(dp[i-3][1][1], dp[i-2][1][1]) + a
else:
    for i, a in enumerate(As):
        if i % 2 == 0:
            dp[i][0][0] = max(dp[i-1][1][0], dp[i-1][1][1])
            dp[i][0][1] = dp[i-1][0][0] + a
            dp[i][1][0] = MINF
            dp[i][1][1] = dp[i-1][1][0] + a
        else:
            dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][0][1])
            dp[i][0][1] = MINF
            dp[i][1][0] = dp[i-1][1][1]
            dp[i][1][1] = dp[i-1][0][0] + a
print(max(dp[N-1][0][0], dp[N-1][0][1], dp[N-1][1][0], dp[N-1][1][1]))