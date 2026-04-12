a,b,c,x,y = map(int,input().split())
c *= 2
if x == y:
    print(min(c*x,a*x+b*y))
if x >y:
    print(min(c*x,c*y+a*(x-y),a*x+b*y))
if x< y:
    print(min(c*y,c*x+b*(y-x),a*x+b*y))