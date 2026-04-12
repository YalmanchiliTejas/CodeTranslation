n = int(input())
a = list(map(int, input().split()))
dp = [[0] * n for _ in range(n)]

# dp[i][j] stores max value of (x-y) in segment from index i to j

for i in range(n):
    dp[i][i] = a[i]
 
for i in range(n - 2, -1, -1):
    for j in range(i + 1, n):
        dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1])
 
print(dp[0][n - 1])