import bisect
from collections import deque
def solve():
  n = int(input())
  a = [int(input()) for _ in range(n)]
  t = 1
  ans = deque([])
  for i,w in enumerate(a):
   if i == 0:
      ans.append(w)
   else:
    
    place = bisect.bisect_left(ans,w)
    if place == 0:
      ans.appendleft(w)
      t += 1
    else:
      ans[place-1] = w

  print(len(ans))
  
  
solve()