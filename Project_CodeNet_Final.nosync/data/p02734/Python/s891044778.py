N,S=map(int,input().split())
*a,=map(int,input().split())
mod=998244353

dp=[[0]*(S+1) for _ in range(N+1)]
dp[0][0]=0
ans=0
for i in range(N):
    dp[i+1][0]+=1
    if a[i]<=S:
        dp[i+1][a[i]]+=1
    for j in range(S+1):
        dp[i+1][j]+=dp[i][j]

        if j>=a[i]:
            dp[i+1][j]+=dp[i][j-a[i]]
        
        dp[i+1][j]%=mod
    ans+=dp[i+1][S]
    ans%=mod


print(ans)