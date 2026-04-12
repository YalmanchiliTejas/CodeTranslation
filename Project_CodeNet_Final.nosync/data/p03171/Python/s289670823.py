N=int(input())
a=list(map(int,input().split()))
dp=[[0]*(N+1) for i in range(N+1)]
for W in range(N):
    for l in range(N-W):
        r=l+W
        if (N-W+1)%2==0:
            dp[l][r]=max(a[l]+dp[l+1][r],dp[l][r-1]+a[r])
        else:
            dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r])
print(dp[0][N-1])