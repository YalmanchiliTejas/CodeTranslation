#C
N=int(input())
A=list(map(int,input().split()))
mod=10**9+7

L=[0 for i in range(N)]
for i in range(N-2,-1,-1):
    L[i]+=A[i+1]+L[i+1]

ans=0
for i in range(N-1):
    ans+=A[i]*L[i]
    ans%=mod
print(ans)