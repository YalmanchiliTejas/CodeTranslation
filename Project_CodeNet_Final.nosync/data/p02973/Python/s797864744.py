import bisect
from collections import deque

n = int(input())
l = deque([int(input())])

for i in range(1, n):
  a = int(input())
  p = bisect.bisect_left(l,a)
  if p == 0:
    l.appendleft(a)
  else:
    l[p-1] = a

print(len(l))