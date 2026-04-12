h,w=map(int,input().split())
a=[]
point=0
for _ in range(h):
	x=input()
	a.append(x)
	point+=x.count("#")
cnt=[[10**10 for _ in range(w)] for _ in range(h)]
for i in range(h):
	for j in range(w):
		if a[i][j]==".":
			cnt[i][j]="."
cnt[0][0]=0
lis=[[0,0]]#tate yoko
p=1
while len(lis)!=0:
	x=list()
	for _ in range(len(lis)):
		k=lis.pop(0)
		if k[0]!=0:
			if cnt[k[0]-1][k[1]]==10**10:
				cnt[k[0]-1][k[1]]=p
				x.append([k[0]-1,k[1]])
		if k[1]!=0:
			if cnt[k[0]][k[1]-1]==10**10:
				cnt[k[0]][k[1]-1]=p
				x.append([k[0],k[1]-1])
		if k[0]!=h-1:
			if cnt[k[0]+1][k[1]]==10**10:
				cnt[k[0]+1][k[1]]=p
				x.append([k[0]+1,k[1]])
		if k[1]!=w-1:
			if cnt[k[0]][k[1]+1]==10**10:
				cnt[k[0]][k[1]+1]=p
				x.append([k[0],k[1]+1])
	lis=x
	p+=1
if cnt[-1][-1]==h+w-2==point-1:
	print("Possible")
else:
	print("Impossible")

