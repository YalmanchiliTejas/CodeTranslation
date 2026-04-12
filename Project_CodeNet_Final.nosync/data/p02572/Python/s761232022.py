N=int(input())
A=list(map(int,input().split()))
p=sum(A)
ans=0
mod=10**9+7
for i in range(N):
  p-=A[i]
  ans+=A[i]*p%mod
  ans%=mod
print(ans)