a,b,c,x,y=map(int,input().split())
if a+b<=2*c:
    print(x*a+y*b)
else:
    p=min(x,y)
    print(p*c*2+(x-p)*min(a,2*c)+(y-p)*min(b,2*c))