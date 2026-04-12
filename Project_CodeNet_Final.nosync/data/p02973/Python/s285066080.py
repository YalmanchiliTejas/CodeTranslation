import bisect
from collections import deque

N = int(input())
A = [int(input()) for _ in range(N)]
dq = deque([A[0]])

for i in range(1, len(A)):
    idx = bisect.bisect_left(dq, A[i])
    if idx == 0:
        dq.appendleft(A[i])
    else:
        dq[idx - 1] = A[i]

print(len(dq))
