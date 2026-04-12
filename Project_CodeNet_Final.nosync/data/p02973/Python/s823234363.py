from collections import deque
import bisect
N = int(input())
A = [int(input()) for _ in range(N)]
d = deque()
for i in range(N):
    p = bisect.bisect_left(d, A[i])
    if p == 0:
        d.appendleft(A[i])
    else:
        d[p - 1] = A[i]
ans = len(d)
print(ans)