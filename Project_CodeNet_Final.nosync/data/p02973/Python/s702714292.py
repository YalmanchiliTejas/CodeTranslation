def bisect_right(a, x, lo=0, hi=None):
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if x > a[mid]:
            hi = mid
        else:
            lo = mid + 1
    return lo

import collections
n = int(input())
dat = []
for i in range(n):
    dat.append(int(input()))
res = collections.deque([])

res.append(dat[0])
import bisect

for i in range(1, n):
    a = bisect_right(res, dat[i])
    #print("2 : {0}".format(a))

    if a == len(res):
        res.append(dat[i])
    else:
        res[a] = dat[i]
print(len(res))
#print(res)