from collections import deque
from bisect import bisect_left
N = int(input())
A = [int(input()) for _ in range(N)]
queue = deque()
for a in A:
    pos = bisect_left(queue, a)
    if (pos == 0):
        queue.appendleft(a)
    else:
        queue[pos-1] = a
print(len(queue))
