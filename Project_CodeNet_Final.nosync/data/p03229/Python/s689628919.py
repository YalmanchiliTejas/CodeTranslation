# C - Align
from collections import deque
n=int(input())
a=[int(input()) for i in range(n)]
a.sort(reverse=True)
b=deque()
for i in range(n):
    t=0
    if i==n-1:
        t=a.pop(0)
        if abs(t-b[0])>=abs(t-b[-1]):
            b.appendleft(t)
        elif abs(t-b[0])<abs(t-b[-1]):
            b.append(t)
        break
    if i%2==0:
        if i==0:
            t=a.pop(0)
            b.append(t)
            continue
        if b[0]>=b[-1]:
            t=a.pop(0)
            b.append(t)
        elif b[0]<b[-1]:
            t=a.pop(0)
            b.appendleft(t)
    else:
        if i==1:
            t=a.pop(-1)
            b.append(t)
            continue
        if b[0]>=b[-1]:
            t=a.pop(-1)
            b.appendleft(t)
        elif b[0]<b[-1]:
            t=a.pop(-1)
            b.append(t)
ans=0
for i in range(n-1):
    ans+=abs(b[i+1]-b[i])
print(ans)
