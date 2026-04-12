n=int(input())
a=[int(x) for x in input().split()]
al=sum(a)
ans=0
mod=10**9+7

for i in range(n):
  al-=a[i]
  ans+=(a[i]*al)%mod
print(ans%mod)
