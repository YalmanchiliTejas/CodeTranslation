n=int(input())
a=list(map(int,input().split()))
dp=[[float("inf")]*(n+1) for _ in range(n)]
z=0
for l in range(n):
    dp[l][l]=0
for k in range(1,n+1):
    for i in range(n-k+1):
        j=i+k
        if 0<=i<=n-2 and 1<=j<=n:
            if (n-(i+j))%2==0: #先手
                dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1])
            else:
                dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1])
        else:
            dp[i][j]=dp[i][j-1]+a[j-1]
print(dp[0][n])