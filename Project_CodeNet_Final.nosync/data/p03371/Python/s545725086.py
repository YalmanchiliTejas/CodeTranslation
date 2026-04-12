a,b,c,x,y=[int(i) for i in input().split()]

if 2*c<(a+b):
    if x>=y:
        if 2*c<a:
            print(2*c*x)
        else:
            print(2*c*y+(x-y)*a)
    else:
        if 2*c<b:
            print(2*c*y)
        else:
            print(2*c*x+(y-x)*b)
else:
    print(a*x+b*y)
    
        
