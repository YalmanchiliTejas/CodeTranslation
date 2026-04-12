import bisect
from collections import deque
de1 = deque()
N = int(input())
A = [0] * N
for i in range(N):
    A[i] = int(input())
de1.appendleft(A[0])
for j in range(1, N):
    if de1[0] >= A[j]:
        de1.appendleft(A[j])
    else:
        de1[bisect.bisect_left(de1, A[j]) - 1] = A[j]
print(len(de1))
