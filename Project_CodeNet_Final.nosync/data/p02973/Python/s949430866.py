import bisect
from collections import deque

N = int(input())
a = []
for _ in range(N):
  a.append(int(input()))

LIS = deque([a[0]])
for i in range(1,N):
    if a[i] > LIS[-1]:
    	LIS[-1] = a[i]
    elif LIS[0] >= a[i]:
    	LIS.appendleft(a[i])
    else:
    	LIS[bisect.bisect_left(LIS, a[i])-1] = a[i]

print(len(LIS))
