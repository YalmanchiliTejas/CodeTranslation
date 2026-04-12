N = int(input())
A = [int(input()) for i in range(N)]

import bisect
from collections import deque

temp = deque()
temp.appendleft(A[0])
for i in range(1,N):
  if temp[0] >= A[i]:
    temp.appendleft(A[i])
  else:
    temp[bisect.bisect_left(temp,A[i])-1] = A[i]
print(len(temp))