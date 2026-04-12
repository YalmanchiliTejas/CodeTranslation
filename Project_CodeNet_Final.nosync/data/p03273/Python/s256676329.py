#入力
h, w = map(int, input().split())
a = [''] * h
for i in range(h):
	a[i] = input()
    
#リストを作っておく
row = [False] * h
col = [False] * w

# "#" となっているところをTrueに変える
for i in range(h):
	for j in range(w):
		if a[i][j] == '#':
			row[i] = True
			col[j] = True

for i in range(h):
	if row[i]:#iがTrueなら
		for j in range(w):
			if col[j]:#jがTrueなら
				print(a[i][j], end = '')#出力
		print()
