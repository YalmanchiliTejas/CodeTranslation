#copipe-benkyo
h, w = map(int, input().split())
a = [''] * h
#print(a)
for i in range(h):
	a[i] = input()
#print(a)

row = [False] * h
col = [False] * w
#print(row)
#print(col)
for i in range(h):
	for j in range(w):
		if a[i][j] == '#':
			row[i] = True
			col[j] = True
#print(row)
#print(col)
for i in range(h):
	if row[i]:
		for j in range(w):
			if col[j]:
				print(a[i][j], end = '')
		print()
