h,w=map(int,input().split())
*l,=eval("input(),"*h)
row=[any(l[i][j]=="#" for i in range(h)) for j in range(w)]
col=["#" in l[i] for i in range(h)]
for i in range(h):
	f=0
	for j in range(w):
		if row[j]&col[i]:
			print(l[i][j],end="")
			f=1
	if f:
		print("")