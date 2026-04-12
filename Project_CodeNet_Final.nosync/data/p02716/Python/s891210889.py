N = int(input()) + 2
X = [0, 0] + list(map(int, input().split()))
dp = [[0, 0] for _ in range(N)]
for i in range(2, N):
    if i%2:
        dp[i][1] = max(dp[i-2][1] + X[i], dp[i-1][1])
        if i!=3:
            dp[i][0] = max(dp[i-2][0] + X[i], dp[i-1][0])
    else:
        dp[i][1] = dp[i-2][1] + X[i]
        if i!=2:
            dp[i][0] = max(dp[i-2][0] + X[i], dp[i-1][1])
if N%2:
    print(dp[-1][0])
else:
    print(dp[-1][1])
