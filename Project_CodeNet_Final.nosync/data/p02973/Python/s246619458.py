import bisect
from collections import deque
n=int(input())
a=deque([int(input())])
for i in range(n-1):
    t=int(input())
    b=bisect.bisect_left(a, t)
    if b==0:
        a.appendleft(t)
    else:
        a[b-1]=t
    #print(a)
print(len(a))