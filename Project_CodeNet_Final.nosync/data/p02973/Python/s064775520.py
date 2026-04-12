from collections import deque
import bisect
n = int(input())
q = deque()

for _ in range(n):
    a = int(input())
    if len(q) == 0:
        q.appendleft(a)
    elif a <= q[0]:
        q.appendleft(a)
    else:
        i = bisect.bisect_right(q, a-1) - 1
        q[i] = a
print(len(q))