a,b,c,x,y=map(int,input().split())
price=0
if a+b>=c*2:
    min_point=min(x,y)
    price +=min_point*c*2
    x -=min_point
    y -=min_point
    if x>y:
        if a>=c*2:
            price +=c*2*x
        else:
            price +=a*x
    elif y>x:
        if b>=c*2:
            price +=c*2*y
        else:
            price +=b*y
    print(price)
else:
    print(a*x+b*y)