import sys
input = sys.stdin.readline
n = int(input())
if n == 1:
  print(1)
  exit()
  
chk = []
for i in range(n):
  a = int(input())
  chk.append((i,a))
  
from bisect import bisect_left,insort_left
from collections import deque
ans = 1

c = deque([])
for j in chk:
  i,a = j
  if i == 0:
    c.append((a,n-i))
  else:
    ind = bisect_left(c,(a,n-i))
    if ind == 0:
      ans += 1
      c.appendleft((a,n-i))
    else:
      c[ind-1] = (a,n-i)
      
print(ans)