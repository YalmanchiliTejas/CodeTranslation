a,b,c,x,y=map(int,input().split())
if (a+b)/2>c:
	C=min(x,y)*2
	if x>y:
		if 2*c>a:
			print(a*(x-y)+c*C)
		else:
			print(c*max(x,y)*2)
	else:
		if 2*c>b:
			print(b*(y-x)+c*C)
		else:
			print(c*max(x,y)*2)
else:
	print(a*x+b*y)