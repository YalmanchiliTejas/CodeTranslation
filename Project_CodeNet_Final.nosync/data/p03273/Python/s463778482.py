h, w = map(int, input().split())

e = [""] * h
for i in range(h):
    e[i] = input()
    

row = [False] * h
col = [False] * w



for i in range(h):
    for j in range(w):
        if e[i][j] == "#":
            row[i] = True
            col[j] = True


for i in range(h):
	if row[i]:
		for j in range(w):
			if col[j]:
				print(e[i][j], end = '')
		print()
