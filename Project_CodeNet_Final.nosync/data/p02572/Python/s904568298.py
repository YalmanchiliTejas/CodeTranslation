n = int(input())
*a,=map(int, input().split())
from itertools import accumulate
acc=list(accumulate([0]+a))
ans=0
mod=10**9+7
for i in range(n-1):
    ans+=a[i]*(acc[-1]-acc[i+1])
    ans%=mod
print(ans)