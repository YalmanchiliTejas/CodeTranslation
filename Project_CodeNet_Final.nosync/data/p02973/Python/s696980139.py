import bisect
from collections import deque

N = int(input())

largest = deque([])
for i in range(N):
    A_i = int(input())
    idx = bisect.bisect_left(largest, A_i)
    if idx == 0:
        largest.appendleft(A_i)
    else:
        largest[idx - 1] = A_i
print(len(largest))
