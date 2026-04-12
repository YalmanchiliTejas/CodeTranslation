a,b,c,x,y=map(int,input().split())
if a+b>c*2:
    if x>y and (x-y)*2*c>(x-y)*a:
        print(2*c*y+(x-y)*a)
    elif x>y and (x-y)*2*c<=(x-y)*a:
        print(2*c*x)
    elif x<=y and (y-x)*2*c>(y-x)*b:
        print(2*c*x+(y-x)*b)
    else:
        print(2*c*y)
else:
    print(a*x+b*y)