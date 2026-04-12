MOD=998244353
N,S=map(int,input().split())
A=list(map(int,input().split()))

dp=[[0]*(S+10) for i in range(N+1)]
for i in range(N):
    for j in range(S+1):
        dp[i+1][j]=dp[i][j]
        dp[i+1][j]+=dp[i][j-A[i]] if j>=A[i] else 0
        dp[i+1][j]+=1 if (j==A[i] or j==0) else 0
        dp[i+1][j]%=MOD
ans=0
for i in range(1,N+1):
    ans=(ans+dp[i][S])%MOD
print(ans)