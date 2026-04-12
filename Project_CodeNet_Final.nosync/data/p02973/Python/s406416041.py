import collections
from collections import deque
import bisect

n=int(input())
a=list(int(input()) for i in range(n))
b=deque()
b.append(-1)


for i in range(n):
    if a[i]>b[0]:
        x=bisect.bisect_right(b,a[i]-1)
        b[x-1]=a[i]
    else:
        b.appendleft(a[i])
print(len(b))