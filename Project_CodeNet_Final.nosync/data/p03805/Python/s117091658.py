import numpy as np
from itertools import permutations
import copy

n,m = map(int, input().split())

adj = np.zeros((n,n))

for _ in range(m):
	a,b = map(int, input().split())
	adj[a-1,b-1] = 1
	adj[b-1,a-1] = 1

cnt = 0
for p in permutations(range(n)):
	if p[0]!=0:
		continue
	tmp_adj = copy.deepcopy(adj)
	for i in range(n-1):
		if tmp_adj[p[i],p[i+1]] != 1:
			# print('invalid:',p)
			break
	else:
		# print('valid:',p)
		cnt += 1

print(cnt)
		