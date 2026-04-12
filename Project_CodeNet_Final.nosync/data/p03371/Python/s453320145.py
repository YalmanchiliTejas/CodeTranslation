a,b,c,x,y = map(int,input().split())
if x >= y:
    print(min(c*2*y+a*(x-y), a*x+b*y, c*2*x))
else:
    print(min(c*2*x+b*(y-x),a*x+b*y, c*2*y))

