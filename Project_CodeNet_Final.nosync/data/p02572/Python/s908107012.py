n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
ans=0
s=sum(a[1:n])
for i in range(n-1):
  ans=(ans+(a[i]*(s%mod))%mod)%mod
  s=s-a[i+1]
print(ans)
