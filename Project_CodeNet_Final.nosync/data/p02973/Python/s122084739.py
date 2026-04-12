from bisect import bisect_left
from collections import deque
N = int(input())
A = [int(input()) for i in range(N)]
cnt, ms, flag = 1, deque(), 1
ms.append(A[0])
for a in A[1:]:
    if a <= ms[0]:
        ms.appendleft(a)
        cnt += 1
    else:
        i = bisect_left(ms, a)-1
        ms[i] = a
print(cnt)
