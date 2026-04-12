
from collections import deque
import bisect


N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

d = deque()

for a in A:
    p = bisect.bisect_left(d, a)
    if p == 0:
        d.appendleft(a)
        continue
    d[p-1] = a

print(len(d))
