import sys
input = sys.stdin.readline
n = int(input())
if n == 1:
  print(1)
  exit()
  
chk = []
for i in range(n):
  a = int(input())
  chk.append(a)
  
from bisect import bisect_left,insort_left
from collections import deque
ans = 0

c = deque([])
for j in chk:
  if i == 0:
    c.append(j)
  else:
    ind = bisect_left(c,j)
    if ind == 0:
      ans += 1
      c.appendleft(j)
    else:
      c[ind-1] = (j)
      
print(ans)