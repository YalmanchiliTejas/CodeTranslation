a,b,c,x,y = map(int,input().split())

if y > x:
    o = c*min(x,y)*2 + b*abs(x-y)
else:
    o = c*min(x,y)*2 + a*abs(x-y)
p = a*x + b*y
q = c*max(x,y)*2

print(min(o,p,q))