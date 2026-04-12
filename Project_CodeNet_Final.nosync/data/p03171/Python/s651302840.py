import sys
input = sys.stdin.readline

N=int(input())
a = list(map(int, input().split()))

dp = [[None]*(N+1) for _ in range(N+1)]
for i in range(N+1):
    dp[i][i]=0
for len in range(1,N+1):
    for i in range(N-len+1):
        j=i+len
        #print(i,j)
        if (N-len)%2==0:
            dp[i][j] = max(dp[i][j-1]+a[j-1], dp[i+1][j]+a[i])
        else:
            dp[i][j] = min(dp[i][j-1]-a[j-1], dp[i+1][j]-a[i])
#print(dp)
print(dp[0][N])