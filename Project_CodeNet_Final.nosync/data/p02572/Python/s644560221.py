N=int(input())
A=list(map(int,input().split()))

limit=10**9+7
S=[0]
for i in range(N):
    A[i]=A[i]%limit
for i in range(1,N):
    S.append((S[i-1]+A[-i])%limit)
ans=0
for i in range(N-1):
    ans+=A[i]*S[-1-i]
    ans=ans%limit
print(ans)
