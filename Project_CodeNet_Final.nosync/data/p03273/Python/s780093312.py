h, w = list(map(int, input().split()))
a = []
b = [0 for i in range(w)]
for i in range(h):
	ai = list(input())
	a.append(ai)
	for j in range(w):
		if b[j] == 0:
			if ai[j] == "#": 
				b[j] = 1
ans = []
for li in a:
	if li == ["." for i in range(w)]:
		h -= 1
	else:
		ans.append(li)
wd = w
ipl = -1
for i in range(w):
	ipl += 1
	if b[i] == 0:
		wd -= 1
		for j in range(h):
			ans[j].pop(ipl)
		ipl -= 1
w = wd
for i in range(h):
	strp = ""
	for j in range(w):
		strp += ans[i][j] 
	print(strp)