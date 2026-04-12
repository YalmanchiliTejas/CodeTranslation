from itertools import *
mod=10**9+7
n=int(input())
a=list(map(int,input().split()))
s=sum(a)
b=list(accumulate(a))
ans=0
for i in range(n):
    ans+=a[i]*(s-b[i])
    ans%=mod
print(ans)