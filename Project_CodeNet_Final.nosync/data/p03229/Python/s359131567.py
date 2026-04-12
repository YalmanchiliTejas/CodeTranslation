import sys
from collections import deque
read = sys.stdin.read

N, *A = map(int, read().split())

A.sort()
A = deque(A)
a = deque()
side = True
a.append(A.popleft())

while A:
    if side:
        a.append(A.pop())
        if A:
            a.appendleft(A.pop())
        side = False
    else:
        a.append(A.popleft())
        if A:
            a.appendleft(A.popleft())
        side = True

if side:
    tmp = a.popleft()
else:
    tmp = a.pop()

if abs(tmp - a[0]) <= abs(tmp - a[-1]):
    a.append(tmp)
else:
    a.appendleft(tmp)

if not side:
    tmp = a.popleft()
else:
    tmp = a.pop()

if abs(tmp - a[0]) <= abs(tmp - a[-1]):
    a.append(tmp)
else:
    a.appendleft(tmp)

answer = 0
a = list(a)
for i, j in zip(a, a[1:]):
    answer += abs(i - j)

print(answer)