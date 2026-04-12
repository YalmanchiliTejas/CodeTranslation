N=int(input())
S=[int(i) for i in input().split()]
T=[set() for i in range(N)]
dp=[0]*(N)
ans=0
mod=10**17
for k in range(1,N):
    for c in range(1,N):
        if k*c>=N-1:
            break
        dp[c]=dp[c]+S[N-1-k*c]+S[k*c]
        a=(N-1-k*c)
        b=a-c
        if b<=0 or (N-1-k*c==k*c) or (N-1-k*c in T[c]) or (k*c in T[c]) :
            dp[c]=-mod
        T[c].add(N-1-k*c)
        T[c].add(k*c)
        ans=max(ans,dp[c])
    #print(dp)
print(ans)