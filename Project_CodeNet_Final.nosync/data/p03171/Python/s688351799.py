import sys
input = sys.stdin.readline
n = int(input())
a = tuple(map(int,input().split()))

dp = [[0]*n for i in range(n)]
if n %2 == 0:
    for i in range(n):
        dp[i][i] = -a[i]
else:
    for i in range(n):
        dp[i][i] = a[i]

for i in range(1,n):
    for j in range(n-i):
        if (n-i)%2 == 1:
            dp[j][i+j] = max(dp[j][i+j-1]+a[i+j],dp[j+1][i+j]+a[j])
        else:
            dp[j][i+j] = min(dp[j][i+j-1]-a[i+j],dp[j+1][i+j]-a[j])
print(dp[0][n-1])