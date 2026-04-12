n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
ans=0
s=sum(a) % mod
for i in a:
  s-=i
  s%=mod
  ans+=i*s
  ans%=mod
print(ans)