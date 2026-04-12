n = int(input())
a = [int(i) for i in input().split()]

dp = [[0] * (n+1) for _ in range(n+1)]


for i in range(n):
    dp[i][i] = 0


for j in range(1, n + 1):
    for i in range(n+1):
        if i + j <= n:
            if j % 2 == n % 2:
                dp[i][i+j] = max(dp[i][i+j-1]+a[i+j-1], a[i]+dp[i+1][i+j])
            else:
                dp[i][i+j] = min(dp[i][i+j-1], dp[i+1][i+j])

print(2*dp[0][n]-sum(a))
