def f(a,i,j,dp):
    if dp[i][j]==-1:
        if i>j:
            return 0

        dp[i][j]=max(a[i]+min(f(a,i+2,j,dp),f(a,i+1,j-1,dp)),
                                a[j]+min(f(a,i+1,j-1,dp),f(a,i,j-2,dp)))
    return dp[i][j]
        
n=int(input())
dp=[[-1 for i in range(n)] for j in range(n)]
a=list(map(int,input().split()))
for i in range(n):
    dp[i][i]=a[i]

for i in range(n-1):
    dp[i][i+1]=max(a[i],a[i+1])

s1=f(a,0,n-1,dp)

print(s1-sum(a)+s1)
