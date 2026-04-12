import sys
input=sys.stdin.readline
n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
a.sort()
from collections import deque
def getsm(q):
    last=q.popleft()
    sm=0
    for num in q:
        sm+=abs(last-num)
        last=num
    return sm

q = deque()
q.append(a[0])
l=0
r=n
while True:
    r-=1
    if r==l:
        break
    q.appendleft(a[r])
    r-=1
    if r==l:
        break
    q.append(a[r])
    l+=1
    if r==l:
        break
    q.appendleft(a[l])
    l+=1
    if r==l:
        break
    q.append(a[l])
ans1=getsm(q)


q = deque()
q.append(a[-1])
l=-1
r=n-1
while True:
    l+=1
    if r==l:
        break
    q.appendleft(a[l])
    l+=1
    if r==l:
        break
    q.append(a[l])
    r-=1
    if r==l:
        break
    q.appendleft(a[r])
    r-=1
    if r==l:
        break
    q.append(a[r])
ans2=getsm(q)
print(max(ans1,ans2))