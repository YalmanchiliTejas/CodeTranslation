import sys
from collections import deque
from bisect import bisect_left, bisect_right

N=input()
A=[ int(sys.stdin.readline().strip())  for _ in range(N) ]

q=deque()

for x in A:
	i=bisect_left(q,x)
	if i==0:
		q.appendleft(x)
	else:
		q[i-1]=x

print len(q)