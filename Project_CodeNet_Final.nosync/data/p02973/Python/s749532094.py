from collections import deque
import bisect
N = int(input())
A = deque()
for _ in range(N):
    x = int(input())
    i = bisect.bisect_left(A,x)
    if i == 0:
        A.appendleft(x)
    else:
        A[i-1] = x

print(len(A))