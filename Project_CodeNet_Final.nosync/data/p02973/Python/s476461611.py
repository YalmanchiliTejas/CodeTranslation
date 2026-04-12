from bisect import bisect_left
from collections import deque
N = int(input())
d = deque()

for i in range(N):
    a = int(input())
    n = bisect_left(d, a)
    if n != 0:
        d[n-1] = a
    else:
        d.appendleft(a)
print(len(d))
