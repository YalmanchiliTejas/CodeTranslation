import bisect
import collections
N = int(input())
A = [int(input()) for i in range(N)]
q = collections.deque([-1])
for x in A:
    id = bisect.bisect_left(q, x)
    # print(id, x, q)
    if id == 0:
        q.appendleft(x)
    else:
        q[id-1] = x
print(len(q))
