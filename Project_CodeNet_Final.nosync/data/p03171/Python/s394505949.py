N = int(input())
a = list(map(int, input().split()))
dp = [[0]*(2*N) for i in range(N)]
for i in range(N):
    dp[i][i] = a[i]
    dp[i][i+N] = -a[i]

for i in range(1, N+1):
    for x in range(N-i):
        dp[x][x+i] = max(a[x]+dp[x+1][x+i+N], a[x+i]+dp[x][x+i-1+N])
        dp[x][x+i+N] = min(dp[x+1][x+i]-a[x], dp[x][x+i-1]-a[x+i])
ans = dp[0][N-1]
print(ans)