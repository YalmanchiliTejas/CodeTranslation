from collections import deque
import bisect

def solve():
  N = int(input())
  A = [int(input()) for i in range(N)]
  q = deque()
  for a in A:
    if len(q) == 0 or a <= q[0]:
      q.appendleft(a)
    else:
      q[bisect.bisect_left(q, a) - 1] = a

  return len(q)

print(solve())