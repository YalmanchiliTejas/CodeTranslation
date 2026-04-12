H, W = map(int, input().split())
mas = []
cut_h = []
cut_w = []

for i in range(H):
	mas.append(list(map(str, input())))
	
for i in range(H):
	flg = 1
	for j in range(W):
		if mas[i][j] == "#":
			flg = 0
			break
	if flg:
		cut_h.append(i)
		
for i in range(W):
	flg = 1
	for j in range(H):
		if mas[j][i] == "#":
			flg = 0
			break
	if flg:
		cut_w.append(i)
		
for i in range(H):
	flg = 1
	for j in range(W):
		if i in cut_h:
			flg = 0
			continue
		if j in cut_w: continue
		print(mas[i][j], end = "")
	if flg:
		print()