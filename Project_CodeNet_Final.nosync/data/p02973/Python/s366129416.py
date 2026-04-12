import sys
import bisect
from collections import deque
input = sys.stdin.readline
n = int(input().strip())
q = deque()
qappL = q.appendleft
for i in range(n):
  a = int(input().strip())
  b = bisect.bisect_left(q,a)
  if b == 0:
    qappL(a)
  else:
    q[b-1] = a
print(len(q))