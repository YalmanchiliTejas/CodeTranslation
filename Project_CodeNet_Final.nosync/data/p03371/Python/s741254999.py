a,b,c,x,y=map(int,input().split())
if a+b>2*c and x>=y:
    if a<2*c:
        print(2*c*y+a*(x-y))
    else:
        print(2*c*x)
elif a+b>2*c and x<y:
    if b<2*c:
        print(2*c*x+b*(y-x))
    else:
        print(2*c*y)
else:
    print(a*x+b*y)