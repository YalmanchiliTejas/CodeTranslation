N, M = map(int, input().split())
A = []

import itertools
import numpy as np
import collections


Dist = np.array([[0]*N]*N)

for i in range (0, M):
	B, C = map(int, input().split())
	Dist[B-1][C-1] = 1
	Dist[C-1][B-1] = 1

V = collections.deque(itertools.permutations(range(0, N), N))

count = 0

while V:
	P = V.popleft()
	if P[0] == 0:
		d = 0
		for i in range (1, N):
			if Dist[P[i]][P[i-1]] == 1:
				d+=1
			else:
				break
		if d == N-1:
			count+=1
	else:
		continue        

print(count)