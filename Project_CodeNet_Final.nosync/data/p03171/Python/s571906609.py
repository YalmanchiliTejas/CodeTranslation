n=int(input())
a=list(map(int,input().split()))
dp=[[0 for i in range(n+1-j)] for j in range(n+1)]
for le in range(1,n+1):
    for i in range(n+1-le):
        if le%2==n%2:
            ret=dp[le-1][i]+a[i+le-1]
            if i+1<=n+1-le:
                ret=max(ret,dp[le-1][i+1]+a[i])
            dp[le][i]=ret
        else:
            ret=dp[le-1][i]-a[i+le-1]
            if i+1<=n+1-le:
                ret=min(ret,dp[le-1][i+1]-a[i])
            dp[le][i]=ret
print(dp[n][0])