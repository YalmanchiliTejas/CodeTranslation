import bisect
from collections import deque
N=int(input())

que=deque([-1])
for i in range(N):
    a=int(input())
    
    if que[0]<a:
        i=bisect.bisect_left(que, a)
        que[i-1]=a
    else:
        que.appendleft(a)

print(len(que))
#print(que)