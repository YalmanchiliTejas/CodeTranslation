n=int(input())
a=list(map(int,input().split()))
s=sum(a)
mod=10**9+7
ans=0
for i in a:
  s-=i
  ans+=(i*s)%mod
  ans%=mod
print(ans)