from collections import deque
import bisect
n = int(input())
L = deque([int(input())])
for i in range(1,n):
    t = int(input())
    k = bisect.bisect_left(L, t)
    if k == 0:
        L.appendleft(t)
    else:
        L[k-1] = t
print(len(L))
