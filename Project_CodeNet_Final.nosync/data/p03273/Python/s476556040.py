h,w=map(int,input().split())
a =['']*h
for i in range(h):
    a[i]=input() #二重配列の入力
row = [False]*h
col = [False]*w
for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            row[i]=True
            col[j]=True #同じ行か列に＃があるところは全てTrueに
for i in range(h):
	if row[i]:
		for j in range(w):
			if col[j]:
				print(a[i][j], end = '') 
		print()