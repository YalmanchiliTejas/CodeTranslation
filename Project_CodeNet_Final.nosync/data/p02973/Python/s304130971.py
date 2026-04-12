from bisect import bisect_left
from collections import deque

n = int(input())
a = [int(input()) for _ in range(n)]
res = deque([a[0]])
for x in a[1:]:
    if x <= res[0]:
        res.appendleft(x)
    else:
        res[bisect_left(res, x) - 1] = x

print(len(res))

