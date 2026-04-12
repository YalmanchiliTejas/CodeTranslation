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
        y = q.popleft()
        p.appendleft(y)
        
        x = q.pop()
        p.append(x)
            
    else:
        y = q.popleft()
        p.append(y)
        
        x = q.pop()
        p.appendleft(x)
    i += 1
p1 = list(p) + list(q)
p2 = list(q) + list(p)
ans1 = 0
ans2 = 0
for i in range(n-1):
    ans1 += abs(p1[i+1]-p1[i])
    ans2 += abs(p2[i+1]-p2[i])
print(max(ans1,ans2))