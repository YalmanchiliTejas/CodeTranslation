import bisect
from collections import deque
N=int(input())
a=[int(input()) for _ in range(N)]
d=deque()

for i in range(N):
    p=bisect.bisect_left(d, a[i])
    #print(a[i], p, d)
    if p==0:
        d.appendleft(a[i])
    else:
        d[p-1]=a[i]
print(len(d))