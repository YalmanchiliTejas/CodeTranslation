a,b,c,x,y=map(int,input().split())



if a+b<2*c:
    print(a*x+b*y)
else:
    if x>y and a>c*2:
        print(c*2*x)
    elif x>y and a<=c*2:
        print(c*2*y+(x-y)*a)
    elif x<=y and b>c*2:
        print(c*2*y)
    elif x<=y and b<=c*2:
        print(c*2*x+(y-x)*b)
    