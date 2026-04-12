import bisect
from collections import deque
N=int(input())
a=deque([int(input())])
for _ in range(N-1):
  num=int(input())
  if num<=a[0]:
    a.appendleft(num)
  else:
    a[bisect.bisect_left(a, num)-1]=num
print(len(a))
