import sys
from collections import deque
from bisect import bisect_left, bisect_right

N=input()
A=[ int(sys.stdin.readline().strip())  for _ in range(N) ]

LIS=[]
for i,x in enumerate(A[::-1]):
	if i==0:
		LIS.append(x)
	elif LIS[-1]<=x:
		LIS.append(x)
	else:
		p=bisect_right(LIS,x)
		LIS[p]=x

print len(LIS)