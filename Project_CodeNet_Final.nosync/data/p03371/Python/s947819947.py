a,b,c,x,y = map(int,input().split())
d = 2*c*min(x,y) + a*max(0,x-y) + b*max(0,y-x)
e = 2*c*max(x,y)
f = a*x + b*y
print(min(d,e,f))