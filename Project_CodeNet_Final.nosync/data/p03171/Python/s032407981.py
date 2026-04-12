n=int(input())
a=list(map(int,input().split()))

dp = [[0 for _ in range(n)] for __ in range(n)]
for i in range(n):
    if n%2 == 1:
        dp[i][0] = a[i]
    else:
        dp[i][0] = -a[i]
for le in range(1,n):
    for i in range(n):
        if i + le >= n: continue
        if (n-le)%2 == 1:
            dp[i][le] = max(dp[i][le-1] + a[i+le], dp[i+1][le-1] + a[i])
        else:
            dp[i][le] = min(dp[i][le-1] - a[i+le], dp[i+1][le-1] - a[i])

print(dp[0][n-1])