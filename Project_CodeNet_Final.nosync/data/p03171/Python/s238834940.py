n=int(input())
a=list(map(int,input().split()))
dp=[[0]*(n+1) for _ in range(n+1)]
for i in range(1,n+1):
    for l in range(n+1):
        r=i+l
        if r>n:
            continue
        if (n-i)%2==0:
            dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r-1])
        else:
            dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r-1])
print(dp[0][n])