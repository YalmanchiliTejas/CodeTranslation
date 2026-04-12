h, w = map(int, input().split())
maps = []
for i in range(h):
	maps.append(str(input()))
row = [False] * h
col = [False] * w
for i in range(h):
	for j in range(w):
		if maps[i][j] == '#':
			row[i] = True
			col[j] = True

for i in range(h):
	if row[i]:
		for j in range(w):
			if col[j]:
				print(maps[i][j], end = '')
		print()
