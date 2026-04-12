n,s=map(int,input().split())
A=[int(i) for i in input().split()]
mod=998244353


dp=[0 for i in range(s+1)]
ans=0
for i in range(n):
    now=A[i]
    for q in range(s-now,-1,-1):
        dp[q+now]+=dp[q]%mod
    if A[i]<=s:
        dp[A[i]]+=i+1
    ans+=dp[s] #*(n-i)
    ans=ans%mod
    #print(dp[s],n-i)
print(ans)