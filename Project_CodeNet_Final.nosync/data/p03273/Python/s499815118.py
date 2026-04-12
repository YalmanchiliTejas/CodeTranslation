H,W = map(int,input().split())
a = ["" for i in range(H)]
h = [True for i in range(H)]
w = [False for i in range(W)]

for i in range(H):
	a[i] = input()
	if a[i] == "."*W:
		h[i] = False
	for j in range(W):
		if a[i][j] == "#":
			w[j] = True

for i in range(H):
	if h[i]:
		z = ""
		for j in range(W):
			if w[j]:
				z += a[i][j]
		print(z)
