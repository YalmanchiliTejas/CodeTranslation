a,b,c,x,y=map(int,input().split())
d=c*2*max(x,y)
if x<y:
	e=c*2*x+b*(y-x)
else:
	e=c*2*y+a*(x-y)
f=a*x+b*y
print(min(d,e,f))