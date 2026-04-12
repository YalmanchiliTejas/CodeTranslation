h,w=map(int,input().split())
a=[list(input()) for _ in range(h)]
ans=[i for i in a if '#' in i]
s=[]
for i in range(w):
	t=0
	for j in a:
		t+=(j[i]=='#')
	if t==0:
		s+=[i]
for i in s[::-1]:
	for j in ans:
		del j[i]
for i in ans:
	print(''.join(i))