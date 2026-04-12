import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
a = list(map(int, input().split()))

dp = [[None]*(n+1) for _ in range(n+1)] # a[i:j]に対する解
for i in range(n+1):
    dp[i][i] = 0
for d in range(1,n+1):
    for i in range(n-d+1):
        j = i + d
        if (n - d)%2==0:
            # 先手
            dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1])
        else:
            dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1])
print(dp[0][n])