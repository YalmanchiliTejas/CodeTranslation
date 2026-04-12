dp={}
n=int(input())
nums=list(map(int,input().split()))
#print(dp)
#print(recursive(0,n-1))
dp=[[0]*(n+1) for _ in range(n+1)]
for i in range(n-1,-1,-1):
    for j in range(i,n,1):
        dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1])
print(dp[0][n-1])

