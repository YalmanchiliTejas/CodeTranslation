a,b,c,x,y=map(int,input().split())
print(min(c*2*min(x,y)+min(max(a*(x-y),b*(y-x)),c*2*abs(x-y)),a*x+b*y))