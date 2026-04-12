#17:21
from collections import deque
import bisect
n = int(input())
now = deque()
for _ in range(n):
  tmp = int(input())
  b = bisect.bisect_left(now,tmp)
  if b != 0:
    now[b-1] = tmp
  else:
    now.appendleft(tmp)
print(len(now))