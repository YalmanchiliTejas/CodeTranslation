n=int(input())
a=list(map(int,input().split()))
sa=sum(a)
s=0
mod=10**9+7
for i in range(n):
  ai=a[i]
  s=(s+ai*(sa-ai))%mod
print((mod+s*((mod+1)//2))%mod)