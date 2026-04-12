n = int(input())
a = [int(input()) for i in range(n)]

from collections import deque
import bisect

d = deque()
for i in range(n):
    idx = bisect.bisect_left(d, a[i])
    if idx == 0:
        d.appendleft(a[i])
    else:
        d[idx-1] = a[i]

print(len(d))