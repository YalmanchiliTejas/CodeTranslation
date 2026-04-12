import bisect
from collections import deque

n = int(input())
A = []
dq_A = deque(A)
count = 0
for _ in range(n):
    a = int(input())
    if len(dq_A) == 0:
        dq_A.appendleft(a)
        count += 1
        continue
    i = bisect.bisect_left(dq_A, a)
    if i == 0:
        dq_A.appendleft(a)
        count += 1
    else:
        dq_A[i-1] = a

ans = count
print(ans)