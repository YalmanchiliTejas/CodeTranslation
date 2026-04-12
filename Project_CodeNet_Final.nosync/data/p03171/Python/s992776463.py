n = int(input())
a = list(map(int, input().split()))
dp = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    dp[i][i] = a[i]
for w in range(1, n):
    for l in range(n - w):
        dp[l][l+w] = max(a[l] - dp[l+1][l+w], a[l+w] - dp[l][l+w-1])
print(dp[0][n-1])