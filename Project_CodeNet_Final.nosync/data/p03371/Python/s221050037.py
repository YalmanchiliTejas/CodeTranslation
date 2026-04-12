a,b,c,x,y=map(int, input().split())

if a+b<2*c:
    print(a*x+b*y)
    
else:
    if 2*c<a:
        a=2*c
    if 2*c<b:
        b=2*c
    if x<y:
        print(c*x*2+b*(y-x))
    else:
        print(c*y*2+a*(x-y))
        
