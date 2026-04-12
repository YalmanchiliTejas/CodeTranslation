n = int(input())
alist=list(map(int,input().split()))

mod = (10**9 + 7)
ans = 0

import numpy
alistsum = numpy.cumsum(alist)
asum = sum(alist)

for i in range(n-1):
    ans += alist[i]*(asum - alist[i])
    asum -= alist[i]
    ans = ans%mod
print(ans)