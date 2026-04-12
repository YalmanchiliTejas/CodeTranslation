N=int(input())
A=[int(input()) for i in range(N)]
from bisect import bisect_left
from collections import deque
l=deque()
for a in A:
    i=bisect_left(l,a)
    if i==0:
        l.appendleft(a)
    else:
        l[i-1]=a
print(len(l))