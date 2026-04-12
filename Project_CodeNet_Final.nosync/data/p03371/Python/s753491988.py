a,b,c,x,y = map(int,input().split())
ab = 2*c
if ab < a+b:
    if x <= y:
        print(min(c*2*(max(x,y)),ab*x+b*(y-x)))
    else:
        print(min(c*2*(max(x,y)),ab*y+a*(x-y)))
else:
    print(a*x+b*y)