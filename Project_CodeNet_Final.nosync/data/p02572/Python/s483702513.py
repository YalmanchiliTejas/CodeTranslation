n=int(input())
A=list(map(int,input().split()))
s=sum(A)
ans=0
mod=10**9+7
for i in range(n-1):
  s=s-A[i]
  ans=(ans+A[i]*s)%mod
print(ans)