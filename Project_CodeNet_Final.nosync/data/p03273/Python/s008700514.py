h,w=map(int,input().split())

res=[]
for i in range(h):
	a=list(input())
	if a.count('.')==w:continue
	res+=list([a]) 
col=[True]*w
for i in range(len(res)):
	for j in range(w):
		if res[i][j]=='#':col[j]=False
		
for i in range(len(res)):
	for j in range(w):
		if col[j]==False:print(res[i][j],end='')
	print()
