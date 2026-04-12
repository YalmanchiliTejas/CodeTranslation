a,b,c,x,y=map(int,input().split())
z=min(x,y)
z_max=max(x,y)
cost=0

if a+b > 2*c:
	cost=min(2*c*z+a*(x-z)+b*(y-z),
	         2*c*z_max)
else:
	cost=a*x + b*y

print(cost)