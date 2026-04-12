a,b,c,x,y = map(int,input().split())

if c*2 < a+b:
    if x >= y:
        if c*2 <= a:
            print(x*c*2)
        else:
            print(y*c*2+abs(x-y)*a)
    else:
        if c*2 <= b:
            print(y*c*2)
        else:
            print(x*c*2+abs(x-y)*b)
else:
    print(a*x+b*y)
        