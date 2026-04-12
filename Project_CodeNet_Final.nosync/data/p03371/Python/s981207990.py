a,b,c,x,y=map(int,input().split())
z,w=min(x,y),max(x,y)
print(min(min(a*x+b*y,a*(x-z)+b*(y-z)+c*z*2),c*2*w))