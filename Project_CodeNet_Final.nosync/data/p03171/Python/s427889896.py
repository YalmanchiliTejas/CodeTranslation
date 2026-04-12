n = int(input())
a = list(map(int,input().split()))
dp = [[0 for _ in range(n)] for j in range(n)]
for i in range(n):
    dp[i][i] = a[i]

for dist in range(1,n):
    for i in range(n-dist):
        j = i + dist
        dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1])

print(dp[0][n-1])