a,b,c,x,y = map(int,input().split())
cx,cy = 0,0
ans = 0

a1 = a*x+b*y
if x<y:
    a2 = 2*c*x + b*(y-x)
else:
    a2 = 2*c*y + a*abs(y-x)
a3 = c*max(x,y)*2
print(min([a1,a2,a3]))
