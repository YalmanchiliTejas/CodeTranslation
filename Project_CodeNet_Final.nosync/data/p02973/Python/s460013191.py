from collections import deque
from bisect import bisect_left as bl
N = int(input())
A = [int(input()) for i in range(N)]

de = deque([])
de.append(A[0])
for a in A[1:]:
    ind = bl(de, a)
    if ind == 0:
        de.appendleft(a)
    else:
        de[ind-1] = a

print(len(de))