INF = float("inf")
n = int(input())
a = list(map(int, input().split())) + ([0]*5)
s = 2 + n % 2 
dp = [[-INF] * s for _ in range(n+5)]
for i in range(s): dp[i][i] = a[i]

for i in range(n):
    for j in range(s):
        dp[i+2][j] = max(dp[i+2][j], dp[i][j] + a[i+2])
        if j == s-1: break
        dp[i+3][j+1] = max(dp[i+3][j+1], dp[i][j] + a[i+3])

print(max([dp[n-i][s-i] for i in range(1, s+1)]))
