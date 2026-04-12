a,b,c,x,y=map(int,input().split())
m=min(a+b,2*c)
if x>=y:print(m*y+min(a,2*c)*(x-y))
else:print(m*x+min(b,2*c)*(y-x))