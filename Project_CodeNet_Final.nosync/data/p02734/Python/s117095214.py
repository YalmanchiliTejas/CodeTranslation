N,S=map(int,input().split())
A=list(map(int,input().split()))
mod=998244353

#左端で考える
#左からiまででjを作る場合の数

dp=[0]*S
dp[0]=1
ans=0

for i in range(N):
    h=dp[:]
    a=A[i]
    if a>S:
        continue
    if a==S:
        ans=(ans+(i+1)*(N-i))%mod
        continue
        
    h[a]=(h[a]+i+1)%mod
    for j in range(a+1,S):
        h[j]=(h[j]+dp[j-a])%mod
    ans=(ans+dp[S-a]*(N-i))%mod
    dp=h
    
print(ans)