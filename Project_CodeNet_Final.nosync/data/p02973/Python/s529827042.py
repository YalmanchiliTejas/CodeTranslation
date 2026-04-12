from bisect import bisect_left
from collections import deque
N = int(input())
ls = deque([])
ans = 0
for i in range(N):
  a = int(input())
  if ls:
    ID = bisect_left(ls, a)
    if ID==0:
      ans += 1
      ls.appendleft(a)
    else:
      ls[ID-1]= a
  else:
    ans += 1
    ls.append(a)
print(ans)