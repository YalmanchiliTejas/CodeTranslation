H, W = map(int,input().split())

A = []
for i in range(H):
	A.append(list(input()))

B = []
for a in A:
	if '#' in a:
		B.append(a)

C = []
for b in zip(*B):
	if '#' in b:
		C.append(b)

for c in zip(*C):
	print(''.join(c))