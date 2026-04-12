from bisect import bisect_left
from collections import deque
N = int(input())
a = int(input())
ls = deque([a])
for i in range(N-1):
  c = int(input())
  ind = bisect_left(ls,c)
  if ind==0:
    ls.appendleft(c)
    continue
  ls[ind-1] = c
print(len(ls))