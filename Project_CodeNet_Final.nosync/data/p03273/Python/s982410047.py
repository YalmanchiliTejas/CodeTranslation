H, W = list(map(int, input().split()))
X = []
h = 0
for i in range(H):
	a = input()
	if a == "." * W:
		pass
	else:
		X.append(list(a))
		h += 1

Y = []
w = 0
for i in range(W):
	x = ""
	for j in range(h):
		x += X[j][i]
	if x == "." * h:
		pass
	else:
		Y.append(list(x))
		w += 1

for i in range(h):
	n = ""
	for j in range(w):
		n += Y[j][i]

	print(n)
