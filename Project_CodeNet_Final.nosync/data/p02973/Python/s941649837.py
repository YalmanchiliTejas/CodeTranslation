n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

import bisect
from collections import deque

lis = deque()
for i in range(n):
    ind = bisect.bisect_left(lis,a[i])
    if ind==0:
        lis.appendleft(a[i])
    else:
        lis[ind-1] = a[i]

print(len(lis))
