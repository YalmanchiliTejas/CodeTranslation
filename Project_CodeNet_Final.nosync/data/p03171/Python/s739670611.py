from collections import deque
N = int(input())
a = list(map(int, input().split()))
dp = [[0]*N for i in range(N+1)]
if N%2 == 1:
    f = 1
else:
    f = -1
for i in range(1,N+1):
    for j in range(N-i+1):
        if f > 0:
            if j+1 < N:
                dp[i][j] = max(dp[i-1][j]+a[j+i-1], dp[i-1][j+1]+a[j])
            else:
                dp[i][j] = dp[i-1][j]+a[j+i-1]
        else:
            if j+1 < N:
                dp[i][j] = min(dp[i-1][j]-a[j+i-1], dp[i-1][j+1]-a[j])
            else:
                dp[i][j] = dp[i-1][j]-a[j+i-1]
    f *= -1
print(dp[N][0])