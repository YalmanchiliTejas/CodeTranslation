n = int(input())
a = list(map(int, input().split()))

dp = [[0 for _ in range(n)] for _ in range(n)]

m = n % 2

if m == 0:
    for i in range(n):
        dp[i][i] = -a[i]
else:
    for i in range(n):
        dp[i][i] = a[i]

for i in range(1, n):
    for x in range(n-i):
        y = x + i
        if i % 2 == m:
            dp[x][y] = min(dp[x+1][y] - a[x], dp[x][y-1] - a[y])
        else:
            dp[x][y] = max(dp[x + 1][y] + a[x], dp[x][y - 1] + a[y])

print(dp[0][n-1])