import sys
n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
dp=[[0 for i in range(n)] for j in range(n)]
for i in range(n):
    dp[i][i]=a[i]
for i in range(2,n+1):
    for j in range(n-i+1):
        k=j+i-1 
        dp[j][k]=max(a[k]-dp[j][k-1],a[j]-dp[j+1][k])
print(dp[0][len(a)-1])