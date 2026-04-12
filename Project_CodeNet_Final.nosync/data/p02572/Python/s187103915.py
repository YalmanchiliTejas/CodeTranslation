N=int(input())
A=[int(r) for r in input().split()]
ans=0
x=0
mod=10**9+7
for i in range(N):
  ans=(ans+A[i]*x)%mod
  x=(x+A[i])%mod
print(ans)