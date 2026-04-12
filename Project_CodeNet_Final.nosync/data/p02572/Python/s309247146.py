N=int(input())
A=list(map(int,input().split()))
mod=10**9+7

S=[sum(A)]
for i in range(N):
    S.append(S[-1]-A[i])

ans=0
for i in range(N):
    ans+=A[i]*(S[i]-A[i])
    ans%=mod
print(ans)