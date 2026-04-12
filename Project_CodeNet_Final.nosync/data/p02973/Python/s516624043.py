from bisect import bisect_left
from collections import deque
n = int(input())

ary = deque([])
for i in range(n):
    a = int(input())
    idx = bisect_left(ary, a)
    if idx == 0:
        ary.appendleft(a)
    else:
        ary[idx-1] = a
print(len(ary))