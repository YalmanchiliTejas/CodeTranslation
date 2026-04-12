n=int(input())
a=list(map(int,input().split()))
ans1=0
ans2=0
inf=-10**18
if n%2:
    dp=[[inf]*3 for i in range(n)]
    dp[0][0]=a[0]
    dp[2][0]=dp[0][0]+a[2]
    for i in range(2,n):
        dp[i][0]=dp[i-2][0]+a[i]
        if i>=3:
            dp[i][1]=max(dp[i-3][0],dp[i-2][1])+a[i]
        else:
            dp[i][1]=dp[i-2][1]+a[i]
        if i>=4:
            dp[i][2]=max(dp[i-4][0],dp[i-3][1],dp[i-2][2])+a[i]
        elif i>=3:
            dp[i][2]=max(dp[i-3][1],dp[i-2][2])+a[i]
        else:
            dp[i][2]=dp[i-2][2]+a[i]
    ans=max(dp[n-3][0],dp[n-2][1],dp[n-1][2])
    # print(dp)
    dp=[[inf]*2 for i in range(n)]
    dp[1][0]=a[1]
    for i in range(3,n):
        dp[i][0]=dp[i-2][0]+a[i]
        dp[i][1]=max(dp[i-3][0],dp[i-2][1])+a[i]
    ans=max(ans,dp[-1][1],dp[-2][0])
    for i in range(2,n,2):
        ans1+=a[i]
    print(max(ans,ans1))
else:
    dp=[[inf]*2 for i in range(n)]
    dp[0][0]=a[0]
    for i in range(2,n):
        dp[i][0]=dp[i-2][0]+a[i]
        if i>2:
            dp[i][1]=max(dp[i-3][0],dp[i-2][1])+a[i]
        else:
            dp[i][1]=dp[i-2][1]+a[i]
    ans=max(dp[-1][1],dp[-2][0])
    for i in range(1,n,2):
        ans1+=a[i]
    print(max(ans1,ans))
