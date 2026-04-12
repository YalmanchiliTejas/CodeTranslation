n=int(input())
a=list(map(int,input().split()))

if n//2==1:
    print(max(a))
    exit()

if n%2==0:
    

    #iは桁数、jはそれまでに余計に飛ばした数
    #dp[i][j]
    dp=[[-10**9]*2 for _ in range(n)]

    for i in range(n):
        if i<2:
            dp[i][0]=a[i]

        if i>=2:
            dp[i][0]=dp[i-2][0]+a[i]
        
        if i>=3:
            dp[i][1]=max(dp[i-2][1]+a[i],dp[i-3][0]+a[i])

    #print(dp)
    print(max([dp[-1][1],dp[-1][0],dp[n-2][0]]))
    

else:
    

    #iは桁数、jはそれまでに余計に飛ばした数
    #dp[i][j]
    dp=[[-10**9]*3 for _ in range(n)]

    for i in range(n):
        if i<2:
            dp[i][0]=a[i]

        if i>=2:
            dp[i][0]=dp[i-2][0]+a[i]
        
        if i>=3:
            dp[i][1]=max(dp[i-2][1]+a[i],dp[i-3][0]+a[i])
            
        if i>=4:
            dp[i][2]=max([dp[i-2][2]+a[i],dp[i-3][1]+a[i],dp[i-4][0]+a[i]])
    #print(dp)
    print(max([dp[-1][2],dp[-1][1],dp[-1][0]-a[0],dp[-1][0]-a[-1]]))
