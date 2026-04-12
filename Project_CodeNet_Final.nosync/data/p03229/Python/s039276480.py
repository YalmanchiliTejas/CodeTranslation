from collections import deque
from copy import deepcopy

n,*a = map(int,open(0).read().split())
acopy = deepcopy(a)
a.sort()
acopy.sort(reverse = True)

L = deque([])
a = deque(a)
acopy = deque(acopy)
Lcopy = deepcopy(L)

max_ = a.pop()
L.append(max_)
min_ = acopy.pop()
Lcopy.append(min_)

while a:
    if a:
        b = a.popleft()
        L.append(b)
    if a:
        c = a.popleft()
        L.appendleft(c)
    if a:
        d = a.pop()
        L.append(d)
    if a:
        e = a.pop()
        L.appendleft(e)

while acopy:
    if acopy:
        b = acopy.popleft()
        Lcopy.append(b)
    if acopy:
        c = acopy.popleft()
        Lcopy.appendleft(c)
    if acopy:
        d = acopy.pop()
        Lcopy.append(d)
    if acopy:
        e = acopy.pop()
        Lcopy.appendleft(e)
ans1,ans2 = 0,0
#print(L,Lcopy)
for i in range(len(L)-1):
    ans1 +=abs(L[i+1] - L[i])
for i in range(len(Lcopy)-1):
    ans2 +=abs(Lcopy[i+1] - Lcopy[i])
print(max(ans1,ans2))