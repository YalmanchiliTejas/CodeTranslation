import sys
from collections import deque
from bisect import bisect_left, bisect_right

N=input()
seq=[ int(sys.stdin.readline().strip())*-1  for _ in range(N) ]

LIS = [seq[0]]
for i in range(len(seq)):
	if i==0: continue
	if seq[i] >= LIS[-1]:
		LIS.append(seq[i])
	else:
		LIS[bisect_right(LIS, seq[i])] = seq[i]

print(len(LIS))