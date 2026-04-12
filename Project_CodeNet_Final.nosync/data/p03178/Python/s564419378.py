s,d=input(),int(input())
n=[int(i) for i in s]
l=len(s)
mod=10**9+7
dp=[[[0]*d,[0]*d] for i in range(l+1)]
dp[0][0][0]=1
for i in range(l):
    for smaller in range(2):
        for j in range(d):
            for x in range(10 if smaller else n[i]+1):
                dp[i+1][smaller or x<n[i]][(j+x)%d] += dp[i][smaller][j]
                dp[i+1][smaller or x<n[i]][(j+x)%d]%=mod
print((dp[l][0][0]+dp[l][1][0]-1)%mod)