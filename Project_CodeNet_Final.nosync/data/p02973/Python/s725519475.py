import bisect
from collections import deque

N = int(input())
A = deque([-1])

for i in range(N):
  a = int(input())
  idx = bisect.bisect_left(A, a)
  if idx == 0:
    A.appendleft(a)
  
  else:
    A[idx-1] = a

print(len(A))