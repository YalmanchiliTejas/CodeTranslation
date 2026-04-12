n = int(input())
a = list(map(int, input().split()))
dp = [[-float('inf')] * (n + 2) for _ in range(2 + n % 2)]
dp[0][0] = 0
if n % 2:
    for i in range(n):
        if i < n - 2:
            dp[2][i + 4] = dp[0][i] + a[i + 2]
        if i < n - 1:
            dp[1][i + 3] = dp[0][i] + a[i + 1]
            dp[2][i + 3] = max(dp[2][i + 3], dp[1][i] + a[i + 1])
        dp[0][i + 2] = dp[0][i] + a[i]
        dp[1][i + 2] = max(dp[1][i + 2], dp[1][i] + a[i])
        dp[2][i + 2] = max(dp[2][i + 2], dp[2][i] + a[i])
    print(max(dp[2][-1], dp[1][-2], dp[0][-3]))
else:
    for i in range(n):
        if i < n - 1:
            dp[1][i + 3] = dp[0][i] + a[i + 1]
        dp[0][i + 2] = dp[0][i] + a[i]
        dp[1][i + 2] = max(dp[1][i + 2], dp[1][i] + a[i])
    print(max(dp[1][-1], dp[0][-2]))
