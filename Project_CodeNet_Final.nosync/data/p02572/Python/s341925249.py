import itertools
n=int(input())
a=list(map(int,input().split()))
gou=sum(a)
mod=10**9+7
ans=0

for i in range(0,n):
  gou-=a[i]
  ans+=(a[i]*gou)%mod
print(ans%mod)
  