

n, s = list(map(int, input().split()))
a = list(map(int, input().split()))
dp = [[None] * (s+1) for _ in range(n+1)]
M = 998244353


for j in range(s+1):
    dp[0][j] = 0
for i in range(n+1):
    dp[i][0] = i+1

for i in range(1,n+1):
    for j in range(1, s+1):
        dp[i][j] = dp[i-1][j]
        if j-a[i-1]>=0:
            dp[i][j] += dp[i-1][j-a[i-1]]
        dp[i][j] %= M
print(sum((dp[i][s] for i in range(n+1)))%M)