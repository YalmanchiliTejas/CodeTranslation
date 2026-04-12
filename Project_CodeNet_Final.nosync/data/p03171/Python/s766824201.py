n = int(input())
a = list(map(int, input().split()))
dp = [[0] * (n-t+1) for t in range(1, n+1)]
dp[0] = a
for t in range(1, n):
    for i in range(n-t):
        dp[t][i] = max(-dp[t-1][i+1] + a[i], -dp[t-1][i] + a[i+t])
print(dp[n-1][0])