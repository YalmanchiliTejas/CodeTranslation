N = int(input())
a = list(map(int, input().split()))
dp = [[0]*N for _ in range(N)]
if N%2 == 0:
    for i in range(N):
        dp[0][i] = -a[i]
else:
    for i in range(N):
        dp[0][i] = a[i]

for i in range(1, N):
    for j in range(N-i):
        if (N-i)%2 == 1:
            dp[i][j] = max(dp[i-1][j]+a[i+j], dp[i-1][j+1]+a[j])
        else:
            dp[i][j] = min(dp[i-1][j]-a[i+j], dp[i-1][j+1]-a[j])
print(dp[-1][0])