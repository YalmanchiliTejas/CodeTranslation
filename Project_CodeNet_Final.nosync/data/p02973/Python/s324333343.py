import bisect
from collections import deque

N = int(input())
A = [int(input()) for _ in range(N)]

L = deque()
L.append(A[0])
for i in range(1, N):
    if A[i] <= L[0]:
        L.appendleft(A[i])
    elif A[i] > L[-1]:
        L[-1] = A[i]
    else:
        idx = bisect.bisect_left(L, A[i])
        L[idx-1] = A[i]
        
print(len(L))