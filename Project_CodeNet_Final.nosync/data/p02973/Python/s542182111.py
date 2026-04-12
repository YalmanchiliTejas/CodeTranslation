import bisect as b
from collections import deque
n=int(input())
ans=1
clist=deque([int(input())])
for i in range(n-1):
    next=int(input())
    pos=b.bisect_left(clist,next)
    if pos==0:
        clist.appendleft(next)
        ans+=1
    else:
        clist[pos-1]=next
print(ans)
