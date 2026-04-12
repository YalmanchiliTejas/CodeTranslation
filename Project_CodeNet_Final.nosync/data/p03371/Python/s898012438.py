a,b,c,x,y=map(int,input().split())
m=max(x,y)
n=min(x,y)

if  m==x:
    mm=a
    nn=b
else:
    mm=b
    nn=a

if (a+b)<=2*c:
    print(a*x+b*y)
else:
    if 2*c*n+mm*(m-n)<=2*c*m:
        print(2*c*n+mm*(m-n))
    else:
        print(2*c*m)