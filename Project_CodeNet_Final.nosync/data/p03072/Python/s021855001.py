N = input()
rs = list(map(int,input().split(' ')))

buf = 0
for i,r in enumerate(rs):
	flg = 0
	for j in range(0,i):
		if(rs[i] < rs[j]):
			flg = 1
		else:
			pass
	if flg == 0:
		buf = buf + 1
print(buf)