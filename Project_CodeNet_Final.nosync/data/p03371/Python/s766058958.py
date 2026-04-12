a,b,c,x,y=map(int, input().split())

if c<=min(a,b)/2:
    print(2*c*max(x,y))
elif c>(a+b)/2:
    print(x*a+y*b)
else:
    if x>=y:
        if c<a/2:
            print(2*c*max(x,y))
            
        else:
            print(2*c*y+(x-y)*a)
    else:
        if c<b/2:
            print(2*c*max(x,y))
        else:    
            print(2*c*x+(y-x)*b)