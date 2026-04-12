a,b,c,x,y=map(int,input().split())
s=a*x+b*y
t=2*c*max(x,y)
u=2*c*min(x,y)+max(a*(x-min(x,y)),b*(y-min(x,y)))
print(min(s,t,u))