n=int(input())
a=list(map(int,input().split()))
mod=10**9+7

s=sum(a)%mod

ans=0

for i in range(n-1):
  r=a[i]%mod
  s=s-r
  ans+=(r*s)%mod
  
print(ans%mod)