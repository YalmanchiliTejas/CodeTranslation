H, W = map(int, input().split())
field = []
for i in range(0, H):
	S = input()
	lst = []
	for j in range(0, W):
		lst.append(S[j])
	if '#' in lst:
		field.append(lst)
for i in range(0, W):
	flag = True
	for j in range(0, len(field)):
		if field[j][i] == '#':
			flag = False
			break
	if flag:
		for j in range(0, len(field)):
			field[j][i] = ''
for i in range(0, len(field)):
	ans = ''
	for j in range(0, W):
		ans = ans + field[i][j]
	print(ans)