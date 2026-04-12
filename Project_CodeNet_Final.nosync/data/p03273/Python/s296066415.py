import numpy as np
import sys

H, W = map(int, raw_input().split())
a = []
for i in range(H):
	_a = list(raw_input())
	a.append(_a)
a = np.array(a)

row_exist = [False] * H
col_exist = [False] * W
for i in range(H):
	if '#' in a[i, :]:
		row_exist[i] = True
for i in range(W):
	if '#' in a[:, i]:
		col_exist[i] = True
for i in range(H):
	for j in range(W):
		if row_exist[i] and col_exist[j]:
			sys.stdout.write(a[i, j])
	if row_exist[i]:
		print ""
