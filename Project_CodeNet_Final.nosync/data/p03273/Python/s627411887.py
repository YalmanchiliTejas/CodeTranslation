H,W=map(int,input().split()[:2])
aHW=[input() for _ in range(H)]
ignoreH=[]
ignoreW=[]

for i in range(H):
	flg=True
	for j in range(W):
		if aHW[i][j]=='#':
			flg=False
			break
	if flg:
		ignoreH.append(i)

for i in range(W):
	flg=True
	for j in range(H):
		if aHW[j][i]=='#':
			flg=False
			break
	if flg:
		ignoreW.append(i)


for i in range(H):
	if i in ignoreH:
		continue
	for j in range(W):
		if j in ignoreW:
			continue
		print(aHW[i][j],end="")
	print()
