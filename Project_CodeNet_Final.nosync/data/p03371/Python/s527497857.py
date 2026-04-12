a,b,c,x,y=map(int,input().split())
if a+b>c*2:
    if x>y:
        print(min(x*c*2,y*c*2+(x-y)*a))
    else:
        print(min(y*c*2,x*c*2+(y-x)*b))
else:
    print(a*x+b*y)