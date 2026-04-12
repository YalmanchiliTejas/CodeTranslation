r,g,b= map(int,input().split())
a=(str(r)+str(g)+str(b))
if int(a)%4==0:
	print('YES')
else:
	print('NO')