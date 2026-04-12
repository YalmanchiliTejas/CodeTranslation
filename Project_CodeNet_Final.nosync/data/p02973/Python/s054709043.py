import bisect
from collections import deque
n = int(input())
c = deque()
for i in range(n):
    a = int(input())
    idx = bisect.bisect_left(c,a)
    if idx == 0:
        c.appendleft(a)
    else:
        c[idx-1] = a
print(len(c))