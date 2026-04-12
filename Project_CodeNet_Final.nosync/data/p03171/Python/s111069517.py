def findans(i,j,li):
    if i>=len(li) or j<0:
        return 0
    if i==j:
        dp[i][j]=li[i]
    if i+1==j:
        dp[i][j]=max(li[i],li[j])
    if dp[i][j]!=-1:
        return dp[i][j]
    ans1=li[i]+min(findans(i+2,j,li),findans(i+1,j-1,li))
    ans2=li[j]+min(findans(i,j-2,li),findans(i+1,j-1,li))
    dp[i][j]=max(ans1,ans2)
    return dp[i][j]
n=int(input())
li=[int(k) for k in input().split()]
dp=[[-1 for i in range(n)] for j in range(n)]
x=sum(li)
a=findans(0,n-1,li)
b=x-a
print(a-b)
