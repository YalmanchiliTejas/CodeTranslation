from collections import defaultdict
n = int(input())
m = n//2
INF = 10**18
dp = [defaultdict(lambda: -INF)for _ in range(n+2)]
for i, a in enumerate(map(int, input().split()), 2):
    for j in range(max(1, i//2-1), -(-i//2)+1):
        if j-1 == 0:
            dp[i-2][j-1] = 0
        dp[i][j] = max(dp[i-1][j], dp[i-2][j-1]+a)

print(dp[n+1][m])
