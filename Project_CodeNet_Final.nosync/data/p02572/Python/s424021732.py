n=int(input())
a=list(map(int,input().split()))
s=sum(a)
ans=0
mod=10**9+7
for i in a:
    ans=(ans+i*(s-i))
print((ans//2)%mod)