from collections import*
from bisect import*
N,*A=map(int,open(0))
q=deque([A[0]])
for x in A[1:]:
	i=bisect_left(q,x)
	if i==0:q.appendleft(x)
	else:q[i-1]=x
print(len(q))