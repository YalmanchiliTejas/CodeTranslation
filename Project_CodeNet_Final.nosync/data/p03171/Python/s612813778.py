#dp=[[ for i in range(3000)] for j in range(3000)]
n=int(input())
A=list(int(i) for i in input().split())
dp=[[0 for i in range(n)] for j in range(n)]
for i in range(n-1,-1,-1):
    for j in range(i,n):
        if i==j:
            dp[i][j]=A[i]
        else:
            dp[i][j]=max(A[i]-dp[i+1][j],A[j]-dp[i][j-1])
print(dp[0][-1])
