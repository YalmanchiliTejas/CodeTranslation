a,b,c,x,y = map(int,input().split())
if a+b < c:
    print(a*x+b*y)
else:
    if x < y:
        print(min(x*c*2+(y-x)*b,y*c*2,a*x+b*y))
    else:
        print(min(y*c*2+(x-y)*a,x*c*2,a*x+b*y))
