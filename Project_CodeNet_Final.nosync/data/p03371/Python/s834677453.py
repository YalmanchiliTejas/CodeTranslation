a,b,c,x,y=map(int,input().split())
print(min(max(x,y)*2*c,a*x+b*y,min(x,y)*2*c+a*(x-min(x,y))+(b*(y-min(x,y)))))