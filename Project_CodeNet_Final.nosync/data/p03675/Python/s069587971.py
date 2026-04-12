n = int(input())
a = list(map(int, input().split()))

from collections import deque

q = deque()
for i in range(len(a)):
    if i & 1:
        q.appendleft(a[i])
    else:
        q.append(a[i])

q = list(q)
if len(q) & 1:
    q = reversed(q)

print(*q)
