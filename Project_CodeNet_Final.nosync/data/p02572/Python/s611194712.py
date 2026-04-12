N=int(input())
A=list(map(int,input().split()))

_sum=sum(A[1:])
mod=10**9+7
re=0
for i in range(0,N-1):
    re+=A[i]*_sum
    _sum-=A[i+1]
    re%=mod
    _sum%=mod
print(re%mod)
