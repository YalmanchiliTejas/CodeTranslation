from bisect import bisect_left
from collections import deque

n = int(input())
a = tuple(int(input()) for _ in range(n))

d = deque()

for ai in a:
    p = bisect_left(d, ai)  # aa以上の最小値のindex
    if p == 0:
        d.appendleft(ai)
    else:
        d[p - 1] = ai
ans = len(d)
print(ans)