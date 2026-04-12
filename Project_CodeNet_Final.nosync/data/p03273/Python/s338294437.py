import numpy as np
from copy import deepcopy
H, W = map(int, input().split())
A = [list(input()) for _  in range(H)]

output = np.array(A)
A = np.array(A)
delcol = []
delrow = []

for i in range(H):
	if all([A[i][j]=='.' for j in range(W)]):
		delrow.append(i)
		continue
for j in range(W):
	if all([A[i,j]=='.' for i in range(H)]):
		delcol.append(j)

output = np.delete(output, delrow, 0)
output = np.delete(output, delcol, 1)

h, w = output.shape
for i in range(h):
	sentence = ''
	for j in range(w):
		sentence += output[i,j]
	print(sentence)



