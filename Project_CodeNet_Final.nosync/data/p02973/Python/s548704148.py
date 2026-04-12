import bisect
from collections import deque

N = int(input())
A = [int(input()) for _ in range(N)]

LDS = deque()
LDS.append(A[0])

for i in range(1,N):
    if LDS[0] >= A[i]:
        LDS.appendleft(A[i])
    else:
        LDS[bisect.bisect_left(LDS,A[i])-1] = A[i]

print(len(LDS))