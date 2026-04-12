a,b,c,x,y=map(int,input().split())
if 2*c>=a+b:
	print(a*x+b*y)
elif x<y:
	print(min(c*2*x+b*(y-x),c*2*y))
else:
	print(min(c*2*y+a*(x-y),c*2*x))