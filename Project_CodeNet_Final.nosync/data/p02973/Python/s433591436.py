N=int(input())
from collections import deque
d = deque([int(input())]) 
import bisect

for i in range(N-1):
  a=int(input())
  if a>d[-1]:
    d[-1]=a
  elif d[0]>=a:
    d.appendleft(a)
  else:
    i=bisect.bisect_left(d,a)
    d[i-1]=a
print(len(d))