r,c=map(int,input().split())
mat=[list(input()) for i in range(r)]

r_chk=[0]*r
c_chk=[0]*c

for i in range(r):
	for j in range(c):
		if mat[i][j]=='#':
			r_chk[i]=1
			c_chk[j]=1

for i in range(r):
	chk=0
	for j in range(c):
		if r_chk[i]==1 and c_chk[j]==1:     
			print(mat[i][j],end='')
			chk=1
	if chk==1:
		print('') 