n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
ans=0

x=sum(a)

for i in a:
  ans+=((x-i)*i)
  
ans//=2

print(ans%mod)

