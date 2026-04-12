a,b,c,x,y = map(int,input().split())
if a+b<=2*c:
    print(a*x+b*y)
else:
    if x<=y:
        print(2*c*x+min(b,2*c)*abs(y-x))
    else:
        print(2*c*y+min(a,2*c)*abs(y-x))