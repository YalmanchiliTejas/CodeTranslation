R,G,B =map(str,input().split())
RGB=R+G+B
if int(RGB) %4 ==0:
	print('YES')
else:
	print('NO')