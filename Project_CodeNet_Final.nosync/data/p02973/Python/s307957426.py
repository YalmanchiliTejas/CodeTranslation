from collections import deque
from bisect import bisect_left

n = int(input())
a = [int(input()) for _ in range(n)]

dq = deque()
for e in a:
    idx = bisect_left(dq, e)
    if idx == 0:
        dq.appendleft(e)
    else:
        dq[idx-1] = e

ans = len(dq)
print(ans)
