a,b,c,x,y=map(int,input().split())

if a+b>2*c:
    if (x<y and b>2*c) or (x>y and a>2*c) :
        nc=2*max(x,y)
        print(c*nc)
    else:
        mi=min(x,y)
        print(c*2*mi+(x-mi)*a+(y-mi)*b)
else:
    print(a*x+b*y)