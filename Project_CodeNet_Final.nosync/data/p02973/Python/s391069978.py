from collections import deque
from bisect import bisect_left

N = int(input())
A = [int(input()) for _ in range(N)]

q = deque([A[0]])

for x in A[1:]:
    i = bisect_left(q,x)
    if i == 0:q.appendleft(x)
    else:q[i-1]=x
print(len(q))
