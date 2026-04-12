n=int(input())
a=[int(i) for i in input().split()]
dp=[[0]*(n+1) for i in range(n+1)]

for w in range(1,n+1):
#for w in range(1,3,1):
#    print(dp[1])
    for l in range(n-w+1):
        r=l+w
        dpl=-dp[l+1][r]+a[l]
        dpr=-dp[l][r-1]+a[r-1]
        dp[l][r]=max(dpl,dpr)
#print()
#for i in dp:
#    print(i)
print(dp[0][n])