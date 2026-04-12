from collections import deque
from bisect import bisect_left
N=int(input())
que=deque()
ans=0
for i in range(N):
    a=int(input())
    b=bisect_left(que,a)
    if b-1<0:
        que.appendleft(a)
        ans+=1
    else:
        que[b-1]=a
print(ans)