from collections import *
from copy import *
n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
a.sort()
a=deque(a)
b=deepcopy(a)
bb=deque()
bb.append(b.pop())
aa=deque()
aa.append(a.popleft())
while a:
    aa.append(a.pop())
    if a:
        aa.appendleft(a.pop())   
    if a:
        aa.append(a.popleft())
    if a:
        aa.appendleft(a.popleft())
ans=0
aa=list(aa)
while b:
    bb.append(b.popleft())
    if b:
        bb.appendleft(b.popleft())
    if b:
        bb.append(b.pop())
    if b:
        bb.appendleft(b.pop())
bb=list(bb)
ans1=0
for i in range(n-1):
    ans+=abs(aa[i]-aa[i+1])
    ans1+=abs(bb[i]-bb[i+1])
print(max(ans1,ans))
