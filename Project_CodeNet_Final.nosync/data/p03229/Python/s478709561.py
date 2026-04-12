from collections import deque
from copy import deepcopy
n=int(input())
a=sorted([int(input()) for _ in range(n)])
c=deepcopy(a)

a=deque(a)
b=deque([a.popleft()])

i=0
while a:
    if (i//2)%2==0:
        if i%2==0:
            deque.append(b,a.pop())
        else:
            deque.appendleft(b,a.pop())
    else:
        if i%2==0:
            deque.append(b,a.popleft())
        else:
            deque.appendleft(b,a.popleft())
    
    i+=1
ans=0
for i in range(1,n):
    ans+=abs(b[i]-b[i-1])

c=deque(c)
b=deque([c.pop()])

i=0
while c:
    if (i//2)%2==0:
        if i%2==0:
            deque.append(b,c.popleft())
        else:
            deque.appendleft(b,c.popleft())
    else:
        if i%2==0:
            deque.append(b,c.pop())
        else:
            deque.appendleft(b,c.pop())
    
    i+=1
cnt=0
for i in range(1,n):
    cnt+=abs(b[i]-b[i-1])
ans=max(ans,cnt)

print(ans)