n = int(input())
a = [0]*n
for i in range(n):
    a[i] = int(input())
a = sorted(a)
from collections import deque
q = deque([])
q.extend(a)
p = deque([])
i = 0
while len(q) > 1:
    if i%2 == 0:
        p.appendleft(q.popleft())
        p.append(q.pop())
    else:
        p.append(q.popleft())
        p.appendleft(q.pop())
    i += 1
p1 = list(p) + list(q)
p2 = list(q) + list(p)
ans1 = 0
ans2 = 0
for i in range(n-1):
    ans1 += abs(p1[i+1]-p1[i])
    ans2 += abs(p2[i+1]-p2[i])
print(max(ans1,ans2))