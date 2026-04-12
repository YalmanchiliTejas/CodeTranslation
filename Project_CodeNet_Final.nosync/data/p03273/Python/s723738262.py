import numpy as np

H, W = map(int, raw_input().split())
a = []
for i in range(H):
	_a = list(raw_input())
	a.append(_a)
a = np.array(a)
b = a.copy()
while True:
	r_exist = False
	c_exist = False
	for i in range(len(a)):
		if not '#' in a[i, :]:
			b = np.delete(a, i, 0)
			r_exist = True
	a = b.copy()
	for i in range(len(b[0])):
		if not '#' in b[:, i]:
			a = np.delete(b, i, 1)
			c_exist = True
	b = a.copy()
	if not (r_exist or c_exist):
		break
for i in b:
	print ('').join(i)
