from collections import deque
import bisect
n = int(input())

dq = deque()
for i in range(n):
    a = int(input())
    index = bisect.bisect_left(dq, a)
    if index == 0:
        dq.appendleft(a)
    else:
        dq[index-1] = a
print(len(dq))