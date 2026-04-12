import numpy as np
h, w = map(int, raw_input().split())
a = []
for i in range(h):
	tmp_a = list(raw_input())
	tmp_a = [1 if j == '#' else 0 for j in tmp_a]
	a.append(tmp_a)
a = np.array(a)
y0, x0 = a.shape
for i in range(x0 + y0):
	a = a[np.any(a == 1, axis=1)]
	a = a[:, np.any(a == 1, axis=0)]
	y, x = a.shape
	if (x0 == x) & (y0 == y):
		break
	else:
		x0, y0 = x, y
a = a.tolist()
for i in range(y):
	ans = ['#' if j == 1 else '.' for j in a[i][:]]
	print ''.join(ans)