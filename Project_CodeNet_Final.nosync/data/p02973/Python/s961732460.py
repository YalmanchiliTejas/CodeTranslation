n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
import bisect
from collections import deque
h=deque()
for i in range(n):
    idx=bisect.bisect_left(h,a[i])
    if idx==0:
        h.appendleft(a[i])
    else:
        h[idx-1]=a[i]

print(len(h))