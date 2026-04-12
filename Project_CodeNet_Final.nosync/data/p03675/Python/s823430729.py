#ARC077C

from collections import deque
d=deque()
n=int(raw_input())
a=raw_input().split()
for i in xrange(n):
 if i%2==n%2:
  d.append(a[i])
 else:
  d.appendleft(a[i])
for i in xrange(n):
 print d[i],
print
