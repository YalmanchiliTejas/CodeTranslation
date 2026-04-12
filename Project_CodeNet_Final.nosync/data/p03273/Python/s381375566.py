h,w=map(int,input().split())
a=[]
for _ in range(h):
	b=[]
	s=input()
	for i in range(w):
		b.append(s[i])
	a.append(b)
	
#タテのチェック
for i in range(w):
	tmp=0
	for j in range(h):
		if a[j][i]=="#":
			tmp=1
	if tmp==0:
		for j in range(h):
			a[j][i]="0"

#ヨコのチェック
for i in range(h):
	if not "#" in a[i][:]:
		a[i][:]=[0]*w

for i in range(h):
	tmpl=[]
	for j in range(w):
		if not a[i][j]=="0":
			tmpl.append(a[i][j])
	if "#" in tmpl or "." in tmpl:
		print("".join(tmpl))		#listを詰めて表示