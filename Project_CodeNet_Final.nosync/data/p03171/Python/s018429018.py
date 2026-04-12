n=int(input())
li=list(map(int,input().split()))
dp=[[0]*n for _ in range(n)]
for l in range(n-1,-1,-1):
    for r in range(l,n):
        if l==r:
            dp[l][r]=li[l]
        else:
            dp[l][r]=max(li[l]-dp[l+1][r],li[r]-dp[l][r-1])
print(dp[0][-1])