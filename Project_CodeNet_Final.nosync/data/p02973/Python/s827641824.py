from heapq import *
from bisect import bisect_right, bisect_left
from collections import deque
N = int(input())
A = [int(input()) for i in range(N)]
lb, ub = 0, N
while lb + 1 < ub:
    mid = (lb+ub)//2
    cnt, ms, flag = 1, deque(), 1
    ms.append(A[0])
    for a in A[1:]:
        if a <= ms[0]:
            ms.appendleft(a)
            cnt += 1
            if cnt > mid:
                flag = 0
                break
        else:
            i = bisect_left(ms, a)-1
            ms[i] = a
    if flag:
        ub = mid
    else:
        lb = mid
cnt, ms, flag = 1, deque(), 1
ms.append(A[0])
for a in A[1:]:
    if a <= ms[0]:
        ms.appendleft(a)
        cnt += 1
        if cnt > mid:
            flag = 0
            break
    else:
        i = bisect_left(ms, a)-1
        ms[i] = a
if flag:
    print(mid)
else:
    print(mid+1)
