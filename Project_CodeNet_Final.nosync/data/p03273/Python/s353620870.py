import numpy as np

H,W = list(map(int, input().split()))

l = [];
for i in range(H):
	r = input()
	if set(r) != {'.'}:
		k = list(r)
		l.append(k)

d = []
for i in range(W):
	p = [[j[i]] for j in l]
	result = []
	for sublist in p:
	    for item in sublist:
	        result.append(item)
	if set(result) == {'.'}:
		d.append(i)

nl = np.array(l)
itr = 0
for x in range(len(d)):
	nl = np.delete(nl, d[x]-itr, 1)
	itr += 1

for i in range(nl.shape[0]):
	for j in range(nl.shape[1]):
		print(nl[i,j],end='')
	print()
