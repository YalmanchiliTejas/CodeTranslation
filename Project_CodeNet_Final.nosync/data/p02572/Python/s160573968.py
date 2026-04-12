n=int(input())
a=[int(i) for i in input().split()]
s=sum(a)
mod=10**9+7
res=0
for i in a:
    s-=i
    res+=i*s%mod
print(res%mod)