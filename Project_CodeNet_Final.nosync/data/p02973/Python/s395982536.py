from bisect import bisect_left
from collections import deque

N=int(input())
minList=deque([])
minmax=-1
for i in range(N):
  if i==0:
    a=int(input())
    minList.append(a)
    minmax=a
  else:
    a=int(input())
    if a<=minmax:
      minmax=a
      minList.appendleft(a)
    else:
      idx=bisect_left(minList,a)
      if idx==1:minmax=a
      minList[idx-1]=a
print(len(minList))