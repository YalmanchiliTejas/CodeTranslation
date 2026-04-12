import bisect
from collections import deque
n=int(input())
A=deque([int(input())])

for i in range(n-1):
  a=int(input())
  b=bisect.bisect_left(A,a,lo=0,hi=len(A))
  if b==0:
    A.appendleft(a)
  else:
    A[b-1]=a
print(len(A))
