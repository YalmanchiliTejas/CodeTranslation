H,W = list(map(int,input().split()))
a = [list(input()) for i in range(H)]
H_new = H
b = []
for h in range(H):
	judge = True
	for w in range(W):
		#print(h,w)
		if a[h][w] != ".":
			judge = False
	if judge:
		H_new -= 1
	else:
		b.append(a[h])
c = []
W_new = W
for w in range(W):
	judge = True
	for h in range(H_new):
		if b[h][w] != ".":
			judge = False
	if judge:
		W_new -= 1
	else:
		b_new = []
		for h in range(H_new):
			b_new.append(b[h][w])
		c.append(b_new)

for h in range(H_new):
	for w in range(W_new):
		print(c[w][h],end = "")
	print("")
