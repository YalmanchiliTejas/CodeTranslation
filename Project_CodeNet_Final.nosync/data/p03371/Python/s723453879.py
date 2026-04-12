a,b,c,x,y=map(int,input().split())
if (a+b)<=2*c:
    print(a*x+b*y)
elif (a+b)>2*c:
    if x==y:
        print(2*x*c)
    elif x<y:
        if b>2*c:
            print(c*2*y)
        else:    
            print(2*x*c+b*(y-x))
    else:
        if a>2*c:
            print(c*2*x)
        else:    
            print(2*y*c+a*(x-y))
    