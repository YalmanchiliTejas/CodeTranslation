from collections import deque
import bisect
N=int(input())
q=deque([int(input())])
for _ in range(1,N):
  A=int(input())
  i=bisect.bisect_right(q,A-1)
  if i==0:
    q.appendleft(A)
  else:
    q[i-1]=A
print(len(q))