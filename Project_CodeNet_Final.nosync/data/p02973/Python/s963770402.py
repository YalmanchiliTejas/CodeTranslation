import bisect
from collections import deque

n = int(input())
la = [int(input()) for _ in range(n)]
result = deque([])

for a in la:
    idx = bisect.bisect_left(result, a)
    if idx==0:
        result.appendleft(a)
    else:
        result[idx - 1] = a
print(len(result))