n=int(input())
tail=[int(input())]
import bisect
from collections import deque
tail=deque(tail)
c=1
for i in range(n-1):
    a=int(input())
    p=bisect.bisect_left(tail,a)
    if p==0:
        tail.appendleft(a)
        c+=1
    else:
        tail[p-1]=a
print(c)
