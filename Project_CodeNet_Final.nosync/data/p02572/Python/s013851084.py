n=int(input())
a=list(map(int, input().split()))

from itertools import accumulate
c=list(accumulate(a))
mod=10**9+7
ans=0
for i in range(n-1):
    ans+=a[i]*(c[n-1]-c[i])
    ans%=mod
print(ans)
