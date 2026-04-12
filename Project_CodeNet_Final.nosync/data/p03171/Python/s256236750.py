import collections
from collections import deque

n=int(input())
a=deque(map(int, input().split()))  
dp=[[0]*(n+1) for i in range(n+1)]

x=0
y=0

for i in range(n-1,-1,-1):
    for j in range(i+1,n+1):
        if (n-(j-i))%2==0:
            dp[i][j]=max(dp[i][j-1]+a[j-1],dp[i+1][j]+a[i])
        else:
            dp[i][j]=min(dp[i][j-1]-a[j-1],dp[i+1][j]-a[i])


print(dp[0][n])
