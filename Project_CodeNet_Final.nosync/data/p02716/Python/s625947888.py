import sys
input=sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
INF=-10**20
dp=[[INF]*5 for i in range(n)]
dp[0]=[a[0],INF,INF,0,INF]
for i in range(0,n-1):
    if i%2==1:
        dp[i+1][1]=max(dp[i+1][1],dp[i][0])
        dp[i+1][3]=max(dp[i+1][3],dp[i][2])
        dp[i+1][2]=max(dp[i+1][2],dp[i][4]+a[i+1])
        dp[i+1][0]=max(dp[i+1][0],dp[i][3]+a[i+1])
        dp[i+1][3]=max(dp[i+1][3],dp[i][3])
        dp[i+1][1]=max(dp[i+1][1],dp[i][1])
    else:
        dp[i+1][3]=max(dp[i+1][3],dp[i][0])
        dp[i+1][4]=max(dp[i+1][4],dp[i][3])
        dp[i+1][2]=max(dp[i+1][2],dp[i][3]+a[i+1])
        dp[i + 1][4] = max(dp[i + 1][4], dp[i][2])
        dp[i + 1][3] = max(dp[i + 1][3], dp[i][1])
        dp[i+1][0]=max(dp[i+1][0],dp[i][1]+a[i+1])
ans=max(dp[n-1][2],dp[n-1][3])
print(int(ans))










