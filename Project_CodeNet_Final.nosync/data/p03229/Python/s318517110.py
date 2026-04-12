from collections import deque
from copy import copy
N = int(input())
A = deque(sorted([int(input()) for _ in range(N)]))
A2 = copy(A)
d = deque()
d.append(A.popleft())
while True:
    try:
        d.append(A.pop())
        d.appendleft(A.pop())
        d.append(A.popleft())
        d.appendleft(A.popleft())
    except IndexError:
        break
ans = 0
for i in range(N-1):
    ans += abs(d[i]-d[i+1])
A = A2
d = deque()
d.append(A.pop())
while True:
    try:
        d.append(A.popleft())
        d.appendleft(A.popleft())
        d.append(A.pop())
        d.appendleft(A.pop())
    except IndexError:
        break
n = 0
for i in range(N-1):
    n += abs(d[i]-d[i+1])
print(max(ans, n))
