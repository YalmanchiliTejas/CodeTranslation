import bisect
from collections import deque
N = int(input())
A = [int(input()) for _ in range(N)]
c = deque()
c.append(A[0])
for i in range(1, N):
    j = bisect.bisect_right(c, A[i]-1)
    if j == 0:
        c.appendleft(A[i])
    else:
        c[j-1] = A[i]
print(len(c))
