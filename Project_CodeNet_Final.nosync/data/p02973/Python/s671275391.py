from collections import deque
import bisect

N = int(input())
h = deque([int(input())])

for _ in range(N-1):
  a = int(input())
  i = bisect.bisect_left(h, a)
  if i == 0:
    h.appendleft(a)
  else:
    h[i-1] = a
    
print(len(h))