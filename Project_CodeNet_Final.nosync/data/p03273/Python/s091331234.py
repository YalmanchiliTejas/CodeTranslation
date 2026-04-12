h, w = map(int, input().split())
S = [input() for i in range(h)]
A = []
for s in S:
	if '#' in s:
		A.append(s)
nh = len(A)
B = [''] * nh
for x in range(w):
	if any(a[x] == '#' for a in A):
		for y in range(nh):
			B[y] += A[y][x]
for b in B:
	print(b)