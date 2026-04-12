H, W = map(int, input().split())
A = list()
for i in range(H):
	A.append(input())
for i in range(H):
	okrow = False
	for k in range(W):
		if A[i][k] == '#':
			okrow = True
	if okrow:
		for j in range(W):
			okcol = False
			for k in range(H):
				if A[k][j] == '#':
					okcol = True
			if okcol:
				print(A[i][j], end = '')
		print()