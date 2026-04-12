a,b,c=map(int,input().split(' '))
d=(b*10+c)%4
if d==0:
	print('YES')
else:
	print('NO')